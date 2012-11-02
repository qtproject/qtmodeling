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

#include "qnode.h"
#include "qnode_p.h"


QT_BEGIN_NAMESPACE_QTUML

QNodePrivate::QNodePrivate() :
    nestedNodes(new QSet<QNode *>)
{
}

QNodePrivate::~QNodePrivate()
{
    delete nestedNodes;
}

/*!
    \class QNode

    \inmodule QtUml

    \brief A node is computational resource upon which artifacts may be deployed for execution. Nodes can be interconnected through communication paths to define network structures.
 */

QNode::QNode(QObject *parent) :
    QObject(*new QNodePrivate, parent),
    _wrappedClass(new QClass(this)),
    _wrappedDeploymentTarget(new QDeploymentTarget(this))
{
}

QNode::QNode(QNodePrivate &dd, QObject *parent) :
    QObject(dd, parent),
    _wrappedClass(new QClass(this)),
    _wrappedDeploymentTarget(new QDeploymentTarget(this))
{
}

QNode::~QNode()
{
}

/*!
    The Nodes that are defined (nested) within the Node.
 */
const QSet<QNode *> *QNode::nestedNodes() const
{
    // This is a read-write association end

    Q_D(const QNode);
    return d->nestedNodes;
}

void QNode::addNestedNode(QNode *nestedNode)
{
    // This is a read-write association end

    Q_D(QNode);
    if (!d->nestedNodes->contains(nestedNode)) {
        d->nestedNodes->insert(nestedNode);

        // Adjust subsetted property(ies)
        d->QNamespacePrivate::addOwnedMember(dynamic_cast<QNamedElement *>(nestedNode));
    }
}

void QNode::removeNestedNode(QNode *nestedNode)
{
    // This is a read-write association end

    Q_D(QNode);
    if (d->nestedNodes->contains(nestedNode)) {
        d->nestedNodes->remove(nestedNode);

        // Adjust subsetted property(ies)
        d->QNamespacePrivate::removeOwnedMember(dynamic_cast<QNamedElement *>(nestedNode));
    }
}

#include "moc_qnode.cpp"

QT_END_NAMESPACE_QTUML

