/*
 Copyright (c) 2008-2018, Benoit AUTHEMAN All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the author or Destrat.io nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL AUTHOR BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

//-----------------------------------------------------------------------------
// This file is a part of the QuickQanava software library.
//
// \file	cpp_sample.cpp
// \author	benoit@destrat.io
// \date	2018 05 24
//-----------------------------------------------------------------------------

// Qt headers
#include <QGuiApplication>
#include <QtQml>
#include <QQuickStyle>

// QuickQanava headers
#include <QuickQanava.h>

#include "./cpp_sample.h"

using namespace qan;

QQmlComponent *CustomGroup::delegate(QQmlEngine &engine) noexcept {
  static std::unique_ptr<QQmlComponent> delegate;
  if (!delegate)
    delegate = std::make_unique<QQmlComponent>(&engine, "qrc:/CustomGroup.qml");
  return delegate.get();
}

qan::Style *CustomGroup::style() noexcept {
  static std::unique_ptr<qan::Style> style;
  if (!style) {
    style = std::make_unique<qan::Style>();
  }
  return style.get();
}

QQmlComponent *CustomNode::delegate(QQmlEngine &engine) noexcept
{
  static std::unique_ptr<QQmlComponent> CustomRectNode_delegate;
  if (!CustomRectNode_delegate)
    CustomRectNode_delegate =
        std::make_unique<QQmlComponent>(&engine, "qrc:/CustomNode.qml");
  return CustomRectNode_delegate.get();
}

qan::NodeStyle *CustomNode::style() noexcept
{
  static std::unique_ptr<qan::NodeStyle> CustomRectNode_style;
  if (!CustomRectNode_style) {
    CustomRectNode_style = std::make_unique<qan::NodeStyle>();
    CustomRectNode_style->setBackColor(QColor("#ff29fc"));
  }
  return CustomRectNode_style.get();
}

QQmlComponent *InputNode::delegate(QQmlEngine &engine) noexcept
{
  static std::unique_ptr<QQmlComponent> CustomRectNode_delegate;
  if (!CustomRectNode_delegate)
    CustomRectNode_delegate =
        std::make_unique<QQmlComponent>(&engine, "qrc:/InputNode.qml");
  return CustomRectNode_delegate.get();
}

qan::NodeStyle *InputNode::style() noexcept
{
  static std::unique_ptr<qan::NodeStyle> CustomRectNode_style;
  if (!CustomRectNode_style) {
    CustomRectNode_style = std::make_unique<qan::NodeStyle>();
    CustomRectNode_style->setBackColor(QColor("#ff29fc"));
  }
  return CustomRectNode_style.get();
}

QQmlComponent *CustomEdge::delegate(QQmlEngine &engine) noexcept {
  static std::unique_ptr<QQmlComponent> CustomEdge_delegate;
  if (!CustomEdge_delegate)
    CustomEdge_delegate =
        std::make_unique<QQmlComponent>(&engine, "qrc:/CustomEdge.qml");
  return CustomEdge_delegate.get();
}

qan::EdgeStyle *CustomEdge::style() noexcept {
  static std::unique_ptr<qan::EdgeStyle> CustomEdge_style;
  if (!CustomEdge_style)
    CustomEdge_style = std::make_unique<qan::EdgeStyle>();
  return CustomEdge_style.get();
}

qan::Group *CustomGraph::insertCustomGroup() {
  return qan::Graph::insertGroup<CustomGroup>();
}

qan::Node *CustomGraph::insertCustomNode() {
  return qan::Graph::insertNode<CustomNode>(nullptr);
}

qan::Node *CustomGraph::insertInputNode() {
  return qan::Graph::insertNode<InputNode>(nullptr);
}

qan::Edge *CustomGraph::insertCustomEdge(qan::Node *source,
                                         qan::Node *destination) {
  const auto engine = qmlEngine(this);
  if (source != nullptr &&
      destination != nullptr &&
      engine != nullptr)
    return qan::Graph::insertEdge<CustomEdge>(*source, destination, nullptr,
                                              CustomEdge::delegate(*engine));
  return nullptr;
}
