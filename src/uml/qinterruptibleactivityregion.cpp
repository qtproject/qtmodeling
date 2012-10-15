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

#include "qinterruptibleactivityregion.h"
#include "qinterruptibleactivityregion_p.h"

#include <QtUml/QActivityEdge>
#include <QtUml/QActivityNode>

QT_BEGIN_NAMESPACE_QTUML

QInterruptibleActivityRegionPrivate::QInterruptibleActivityRegionPrivate(QInterruptibleActivityRegion *q_umlptr) :
    interruptingEdges(new QSet<QActivityEdge *>),
    nodes(new QSet<QActivityNode *>)
{
    this->q_umlptr = q_umlptr;
}

QInterruptibleActivityRegionPrivate::~QInterruptibleActivityRegionPrivate()
{
    delete interruptingEdges;
    delete nodes;
}

/*!
    \class QInterruptibleActivityRegion

    \inmodule QtUml

    \brief An interruptible activity region is an activity group that supports termination of tokens flowing in the portions of an activity.
 */

QInterruptibleActivityRegion::QInterruptibleActivityRegion(QObject *parent)
    : QObject(parent)
{
    d_umlptr = new QInterruptibleActivityRegionPrivate(this);
}

QInterruptibleActivityRegion::QInterruptibleActivityRegion(bool createPimpl, QObject *parent)
    : QObject(parent)
{
    if (createPimpl)
        d_umlptr = new QInterruptibleActivityRegionPrivate;
}

QInterruptibleActivityRegion::~QInterruptibleActivityRegion()
{
}

/*!
    The edges leaving the region that will abort other tokens flowing in the region.
 */
const QSet<QActivityEdge *> *QInterruptibleActivityRegion::interruptingEdges() const
{
    // This is a read-write association end

    QTUML_D(const QInterruptibleActivityRegion);
    return d->interruptingEdges;
}

void QInterruptibleActivityRegion::addInterruptingEdge(QActivityEdge *interruptingEdge)
{
    // This is a read-write association end

    QTUML_D(QInterruptibleActivityRegion);
    if (!d->interruptingEdges->contains(interruptingEdge)) {
        d->interruptingEdges->insert(interruptingEdge);

        // Adjust opposite property
        interruptingEdge->setInterrupts(this);
    }
}

void QInterruptibleActivityRegion::removeInterruptingEdge(QActivityEdge *interruptingEdge)
{
    // This is a read-write association end

    QTUML_D(QInterruptibleActivityRegion);
    if (d->interruptingEdges->contains(interruptingEdge)) {
        d->interruptingEdges->remove(interruptingEdge);

        // Adjust opposite property
        interruptingEdge->setInterrupts(0);
    }
}

/*!
    Nodes immediately contained in the group.
 */
const QSet<QActivityNode *> *QInterruptibleActivityRegion::nodes() const
{
    // This is a read-write association end

    QTUML_D(const QInterruptibleActivityRegion);
    return d->nodes;
}

void QInterruptibleActivityRegion::addNode(QActivityNode *node)
{
    // This is a read-write association end

    QTUML_D(QInterruptibleActivityRegion);
    if (!d->nodes->contains(node)) {
        d->nodes->insert(node);

        // Adjust subsetted property(ies)
        d->addContainedNode(node);

        // Adjust opposite property
        node->addInInterruptibleRegion(this);
    }
}

void QInterruptibleActivityRegion::removeNode(QActivityNode *node)
{
    // This is a read-write association end

    QTUML_D(QInterruptibleActivityRegion);
    if (d->nodes->contains(node)) {
        d->nodes->remove(node);

        // Adjust subsetted property(ies)
        d->removeContainedNode(node);

        // Adjust opposite property
        node->removeInInterruptibleRegion(this);
    }
}

#include "moc_qinterruptibleactivityregion.cpp"

QT_END_NAMESPACE_QTUML

