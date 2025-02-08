#include "brpch.h"
#include "Model.h"

#include <glad/glad.h>


Model::Model(std::string objectFile)
{
    LoadModel(objectFile);
}

void Model::LoadModel(std::string objectFile)
{
    std::cout << "Inside LoadModel()" << "\n";
    SetModelText(objectFile);
    std::string modelText = GetModelText();
    ParseModelText(modelText);
}


// Load the model data from .obj file into an std::string object.
void Model::SetModelText(std::string objectFile)
{
    std::cout << "Inside SetModelText()" << "\n";
    std::ifstream objIn(objectFile, std::ios::in);
    std::string modelText;
    if (objIn)
    {
        objIn.seekg(0, std::ios::end);
        int size = objIn.tellg();

        std::cout << "Size of Object File = " << size << "\n";

        if (size != -1)
        {
            modelText.resize(size);
            objIn.seekg(0, std::ios::beg);
            objIn.read(&modelText[0], size);
            std::cout << "File read in! \n";
        }
    }

    m_ModelText = modelText;
}

void Model::ParseModelText(std::string modelText)
{
    std::cout << "Inside ParseModelText()" << "\n";
    int StartPos = 0;
    int LineBegin = StartPos;
    std::string tempLine;
    bool EndOfFile = false;
    std::vector<float> vertices(20000);
    std::vector<int> indices(20000);
    int vertexCount = 0;
    int indexCount = 0;


    while (!EndOfFile)
    {
        //std::cout << "LineBegin = " << LineBegin << "\n";
        int LineEnd = modelText.find("\n", LineBegin);
        //std::cout << "LineEnd = " << LineEnd << "\n";
        std::string CurrentLine = modelText.substr(LineBegin, LineEnd - LineBegin);
        LineBegin = modelText.find_first_not_of("\n", LineEnd);
        //std::cout << CurrentLine << "\n";

        if (CurrentLine[0] == 'v')
        {
            if (CurrentLine[1] == ' ')
            {
                int pos = CurrentLine.find_first_of(" ");
                int eol = CurrentLine.find_first_of("\n");

                while (pos != -1)
                {
                    int nextPos = CurrentLine.find(" ", pos + 1);
                    tempLine = CurrentLine.substr(pos, nextPos - pos);
                    // Get value out of "9//9" to get the indices
                    float vertex = std::stof(tempLine);
                    vertices[vertexCount] = vertex;
                    //std::cout << vertex << "\n";
                    pos = nextPos;
                    //std::cout << nextPos << "\n";
                    vertexCount++;
                    //std::cout << "Vertex Count = " << vertexCount << "\n";
                }
            }
        }

        if (CurrentLine[0] == 'f')
        {
            int pos = 0;
            for (int i = 0; i < 3; i++)
            {
                int newPos = CurrentLine.find_first_of(" ", pos);
                //std::cout << newPos << "\n";
                int slashPosition = CurrentLine.find_first_of("/", newPos);
                //std::cout << slashPosition << "\n";
                std::string newIndex = CurrentLine.substr(newPos, slashPosition - newPos);
                //std::cout << newIndex << "\n";

                int index = std::stoi(newIndex);
                indices[indexCount] = index;
                //std::cout << index << "\n";

                newPos = slashPosition;
                pos = newPos;

                indexCount++;
                //std::cout << "Index Count = " << indexCount << "\n";
            }
        }

        if (LineBegin == -1)
        {
            EndOfFile = true;
            std::cout << vertices.size() << " and " << indices.size() << "\n";
            vertices.resize(vertexCount);
            indices.resize(indexCount);

            /*
            for (int i = 0; i < vertices.size(); i++)
            {
                std::cout << "Vertex = " << vertices[i] << "\n";
            }

            for (int i = 0; i < indices.size(); i++)
            {
                std::cout << "Index = " << indices[i] << "\n";
            }
            */

            std::cout << "There are " << indexCount << "indices. \n";
            std::cout << "The 1st and 10th are " << indices[0] << " and " << indices[9] << "\n";
            std::cout << "There are " << vertexCount << "vertices. \n";
            std::cout << "The 1st and 10th are " << vertices[0] << " and " << vertices[9] << "\n";
            std::cout << vertices.size() << " and " << indices.size() << "\n";

            m_VertexCount = vertexCount;
            m_IndexCount = indexCount;
            //m_Vertices = vertices;
            m_Indices = indices;

            std::cout << "Model Parsed" << "\n";

            // Resize model
            auto maxIt = std::max_element(vertices.begin(), vertices.end());
            float maxVal = *maxIt;

            std::cout << "Largest element: " << maxVal << std::endl;

            for (int i = 0; i < vertices.size(); i++)
            {
                vertices[i] = vertices[i] / maxVal;
            }

            m_Vertices = vertices;

        }
        else
        {
            EndOfFile = false;
        }
    }
}

void Model::ModelToOpenGL()
{
    glGenVertexArrays(1, &m_ModelVertexArray);
    glGenBuffers(1, &m_ModelVertexBuffer);
    glGenBuffers(1, &m_ModelIndexBuffer);

    glBindVertexArray(m_ModelVertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, m_ModelVertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_Vertices), &m_Vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ModelIndexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_Indices), &m_Indices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    //glBindVertexArray(0);

}