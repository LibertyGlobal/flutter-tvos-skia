/*
 * Copyright 2021 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef skgpu_Attribute_DEFINED
#define skgpu_Attribute_DEFINED

#include "experimental/graphite/src/DrawTypes.h"

namespace skgpu {

 /** Describes a vertex or instance attribute. */
class Attribute {
public:
    constexpr Attribute() = default;
    constexpr Attribute(const char* name,
                        VertexAttribType cpuType,
                        SLType gpuType)
            : fName(name), fCPUType(cpuType), fGPUType(gpuType) {
        SkASSERT(name && gpuType != SLType::kVoid);
    }
    constexpr Attribute(const Attribute&) = default;

    Attribute& operator=(const Attribute&) = default;

    constexpr bool isInitialized() const { return fGPUType != SLType::kVoid; }

    constexpr const char*      name()    const { return fName; }
    constexpr VertexAttribType cpuType() const { return fCPUType; }
    constexpr SLType           gpuType() const { return fGPUType; }

    constexpr size_t size()       const { return VertexAttribTypeSize(fCPUType); }
    constexpr size_t sizeAlign4() const { return SkAlign4(this->size()); }

private:
    const char* fName = nullptr;
    VertexAttribType fCPUType = VertexAttribType::kFloat;
    SLType fGPUType = SLType::kVoid;
};

} // namespace skgpu

#endif // skgpu_Attribute_DEFINED
