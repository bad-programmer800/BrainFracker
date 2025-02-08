#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>




class Model
{
private:
    // MEMBER VARIABLES
    std::string m_ModelText;
    std::string m_ModelName = "Model";
    int m_VertexCount = 0;
    int m_IndexCount = 0;
    std::vector<float> m_Vertices;
    std::vector<int> m_Indices;

    unsigned int m_ModelVertexArray;
    unsigned int m_ModelVertexBuffer;
    unsigned int m_ModelIndexBuffer;

public:
    Model() = default;
    Model(std::string objectFile);


    // Takes in a file name and sets model data.
    void LoadModel(std::string objectFile);

    // Inside LoadModel() we have some parts
    // 1. Read in the model text and store it in a member variable std::string m_ModelText
    void SetModelText(std::string objectFile);

    // 2. Process the Model Text and store data in member variables.
    void ParseModelText(std::string modelText);

    // 3. Use member variables to build OpenGL Vertex Array Object
    void ModelToOpenGL();

    // Getters
    std::string GetModelText() const { return m_ModelText; }
    std::string GetModelName() const { return m_ModelName; }

    int GetVertexCount() const { return m_VertexCount; }
    int GetIndexCount() const { return m_IndexCount; }
    std::vector<float> GetVertices() const { return m_Vertices; }
    std::vector<int> GetIndices() const { return m_Indices; }

    unsigned int GetModelVertexArray() const { return m_ModelVertexArray; }
    unsigned int GetModelIndexBuffer() const { return m_ModelIndexBuffer; }
    unsigned int GetModelIndexBufferSize() { return sizeof(m_ModelIndexBuffer); }

};