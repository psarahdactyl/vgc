// Copyright 2017 The VGC Developers
// See the COPYRIGHT file at the top-level directory of this distribution
// and at https://github.com/vgc.io/vgc/blob/master/COPYRIGHT
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef VGC_SCENE_SCENE_H
#define VGC_SCENE_SCENE_H

#include <memory>
#include <vector>
#include <QObject>
#include <vgc/geometry/point.h>
#include <vgc/scene/api.h>

namespace vgc {
namespace scene {

class VGC_SCENE_API Scene: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Scene)

public:
    Scene();

    void addPoint();
    void addPoint(const geometry::Point& point);

    const std::vector<geometry::Point>& points() const { return points_; }
    void setPoints(const std::vector<geometry::Point>& points);

Q_SIGNALS:
    void changed();

private:
    std::vector<geometry::Point> points_;
};

using ScenePtr = std::shared_ptr<Scene>;

} // namespace scene
} // namespace vgc

#endif // VGC_SCENE_SCENE_H