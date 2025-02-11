#pragma once

#include "Brain.h"
#include "Panels/atlas3D_panel.h"
#include "Panels/atlas2D_panel.h"
#include "Panels/atlasControls_panel.h"

namespace Brain {

	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;
	private:
		Brain::OrthographicCameraController m_CameraController;

		// Temp
		Ref<VertexArray> m_SquareVA;
		Ref<Shader> m_FlatColorShader;
		Ref<Framebuffer> m_Framebuffer;

		Ref<Texture2D> m_CheckerboardTexture;
		// OpenCV
		Ref<Texture2D> m_cvSourceImageTexture;
		// END OpenCV

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };

		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
	
		// PANELS
		Atlas3DPanel m_Atlas3DPanel;
		Atlas2DPanel m_Atlas2DPanel;
		AtlasControlPanel m_AtlasControlPanel;
	
	
	};

}