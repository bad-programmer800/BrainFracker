#pragma once

#include <string>

#include "Brain/Core/Base.h"
#include <opencv2/opencv.hpp>

namespace Brain {

	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual uint32_t GetRendererID() const = 0;

		virtual void SetData(void* data, uint32_t size) = 0;

		virtual void Bind(uint32_t slot = 0) const = 0;

		virtual bool operator==(const Texture& other) const = 0;
	};

	class Texture2D : public Texture
	{
	public:
		static Ref<Texture2D> Create(uint32_t width, uint32_t height);
		static Ref<Texture2D> Create(const std::string& path);

		// BEGIN: Try to create an overload for a cv::Mat
		static Ref<Texture2D> Create(cv::Mat cvImage);
		// END - define in Texture.cpp
	};

}