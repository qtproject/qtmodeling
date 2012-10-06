/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qobjectflow.h"

QT_BEGIN_NAMESPACE_QTUML

class QObjectFlowPrivate
{
public:
    explicit QObjectFlowPrivate();
    virtual ~QObjectFlowPrivate();

    bool isMulticast;
    bool isMultireceive;
    QBehavior *selection;
    QBehavior *transformation;
};

QObjectFlowPrivate::QObjectFlowPrivate() :
    isMulticast(false),
    isMultireceive(false)
{
}

QObjectFlowPrivate::~QObjectFlowPrivate()
{
}

/*!
    \class QObjectFlow

    \inmodule QtUml

    \brief An object flow is an activity edge that can have objects or data passing along it.Object flows have support for multicast/receive, token selection from object nodes, and transformation of tokens.
 */

QObjectFlow::QObjectFlow(QObject *parent)
    : QObject(parent), d_ptr(new QObjectFlowPrivate)
{
}

QObjectFlow::~QObjectFlow()
{
    delete d_ptr;
}

/*!
    Tells whether the objects in the flow are passed by multicasting.
 */
bool QObjectFlow::isMulticast() const
{
    return d_ptr->isMulticast;
}

void QObjectFlow::setMulticast(bool isMulticast)
{
    d_ptr->isMulticast = isMulticast;
}

/*!
    Tells whether the objects in the flow are gathered from respondents to multicasting.
 */
bool QObjectFlow::isMultireceive() const
{
    return d_ptr->isMultireceive;
}

void QObjectFlow::setMultireceive(bool isMultireceive)
{
    d_ptr->isMultireceive = isMultireceive;
}

/*!
    Selects tokens from a source object node.
 */
QBehavior *QObjectFlow::selection() const
{
    return d_ptr->selection;
}

void QObjectFlow::setSelection(const QBehavior *selection)
{
    d_ptr->selection = const_cast<QBehavior *>(selection);
}

/*!
    Changes or replaces data tokens flowing along edge.
 */
QBehavior *QObjectFlow::transformation() const
{
    return d_ptr->transformation;
}

void QObjectFlow::setTransformation(const QBehavior *transformation)
{
    d_ptr->transformation = const_cast<QBehavior *>(transformation);
}

#include "moc_qobjectflow.cpp"

QT_END_NAMESPACE_QTUML

