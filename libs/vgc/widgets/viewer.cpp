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

#include <vgc/widgets/viewer.h>

#include <QPainter>
#include <vgc/scene/scene.h>

namespace vgc {
namespace widgets {

Viewer::Viewer(scene::Scene* scene, QWidget* parent) :
    QWidget(parent),
    scene_(scene)
{

}

Viewer::~Viewer()
{

}

void Viewer::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    double pointRadius = 10.0;
    for (const geometry::Point& p: scene()->points()) {
        painter.drawEllipse(QPointF(p.x(), p.y()), pointRadius, pointRadius);
    }
}

} // namespace widgets
} // namespace vgc