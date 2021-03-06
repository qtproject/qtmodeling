/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "qumlactivityedge.h"

#include <QtUml/QUmlActivity>
#include <QtUml/QUmlActivityGroup>
#include <QtUml/QUmlActivityNode>
#include <QtUml/QUmlActivityPartition>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlInterruptibleActivityRegion>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlStructuredActivityNode>
#include <QtUml/QUmlValueSpecification>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlActivityEdge

    \inmodule QtUml

    \brief Activity edges can be contained in interruptible regions.An activity edge is an abstract class for directed connections between two activity nodes.

    \b {QUmlActivityEdge is an abstract class.}
 */

/*!
    Creates a new QUmlActivityEdge.
*/
QUmlActivityEdge::QUmlActivityEdge() :
    _activity(0),
    _guard(0),
    _inStructuredNode(0),
    _interrupts(0),
    _source(0),
    _target(0),
    _weight(0)
{
}

/*!
    Destroys the QUmlActivityEdge.
 */
QUmlActivityEdge::~QUmlActivityEdge()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlActivityEdge.
*/
QModelingElement *QUmlActivityEdge::clone() const
{
    QUmlActivityEdge *c = new QUmlActivityEdge;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    c->setLeaf(isLeaf());
    if (guard())
        c->setGuard(dynamic_cast<QUmlValueSpecification *>(guard()->clone()));
    if (weight())
        c->setWeight(dynamic_cast<QUmlValueSpecification *>(weight()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Activity containing the edge.

    \b {Subsetted property(ies):} QUmlElement::owner().

    \b {Opposite property(ies):} QUmlActivity::edges().
 */
QUmlActivity *QUmlActivityEdge::activity() const
{
    // This is a read-write association end

    return _activity;
}

/*!
    Adjusts activity to \a activity.
 */
void QUmlActivityEdge::setActivity(QUmlActivity *activity)
{
    // This is a read-write association end

    if (_activity != activity) {
        // Adjust subsetted properties

        _activity = activity;
        if (activity && activity->asQModelingObject() && this->asQModelingObject())
            QObject::connect(activity->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setActivity()));

        // Adjust subsetted properties
        setOwner(activity);
    }
}

/*!
    Specification evaluated at runtime to determine if the edge can be traversed.

    \b {Subsetted property(ies):} QUmlElement::ownedElements().
 */
QUmlValueSpecification *QUmlActivityEdge::guard() const
{
    // This is a read-write association end

    return _guard;
}

/*!
    Adjusts guard to \a guard.
 */
void QUmlActivityEdge::setGuard(QUmlValueSpecification *guard)
{
    // This is a read-write association end

    if (_guard != guard) {
        // Adjust subsetted properties
        removeOwnedElement(_guard);

        _guard = guard;
        if (guard && guard->asQModelingObject() && this->asQModelingObject())
            QObject::connect(guard->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setGuard()));
        guard->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        if (guard) {
            addOwnedElement(guard);
        }
    }
}

/*!
    Groups containing the edge.

    \b {This is a read-only derived union property.}

    \b {Opposite property(ies):} QUmlActivityGroup::containedEdges().
 */
const QSet<QUmlActivityGroup *> QUmlActivityEdge::inGroups() const
{
    // This is a read-only derived union association end

    return _inGroups;
}

/*!
    Adds \a inGroup to inGroups.

    \sa inGroups(), removeInGroup()
 */
void QUmlActivityEdge::addInGroup(QUmlActivityGroup *inGroup)
{
    // This is a read-only derived union association end

    if (!_inGroups.contains(inGroup)) {
        _inGroups.insert(inGroup);
        if (inGroup && inGroup->asQModelingObject() && this->asQModelingObject())
            QObject::connect(inGroup->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeInGroup(QObject *)));

        // Adjust opposite properties
        if (inGroup) {
            inGroup->addContainedEdge(this);
        }
    }
}

/*!
    Removes \a inGroup from inGroups.

    \sa inGroups(), addInGroup()
 */
void QUmlActivityEdge::removeInGroup(QUmlActivityGroup *inGroup)
{
    // This is a read-only derived union association end

    if (_inGroups.contains(inGroup)) {
        _inGroups.remove(inGroup);

        // Adjust opposite properties
        if (inGroup) {
            inGroup->removeContainedEdge(this);
        }
    }
}

/*!
    Partitions containing the edge.

    \sa addInPartition(), removeInPartition()

    \b {Subsetted property(ies):} QUmlActivityEdge::inGroups().

    \b {Opposite property(ies):} QUmlActivityPartition::edges().
 */
const QSet<QUmlActivityPartition *> QUmlActivityEdge::inPartitions() const
{
    // This is a read-write association end

    return _inPartitions;
}

/*!
    Adds \a inPartition to inPartitions.

    \sa inPartitions(), removeInPartition()
 */
void QUmlActivityEdge::addInPartition(QUmlActivityPartition *inPartition)
{
    // This is a read-write association end

    if (!_inPartitions.contains(inPartition)) {
        _inPartitions.insert(inPartition);
        if (inPartition && inPartition->asQModelingObject() && this->asQModelingObject())
            QObject::connect(inPartition->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeInPartition(QObject *)));

        // Adjust subsetted properties
        addInGroup(inPartition);

        // Adjust opposite properties
        if (inPartition) {
            inPartition->addEdge(this);
        }
    }
}

/*!
    Removes \a inPartition from inPartitions.

    \sa inPartitions(), addInPartition()
 */
void QUmlActivityEdge::removeInPartition(QUmlActivityPartition *inPartition)
{
    // This is a read-write association end

    if (_inPartitions.contains(inPartition)) {
        _inPartitions.remove(inPartition);

        // Adjust subsetted properties
        removeInGroup(inPartition);

        // Adjust opposite properties
        if (inPartition) {
            inPartition->removeEdge(this);
        }
    }
}

/*!
    Structured activity node containing the edge.

    \b {Subsetted property(ies):} QUmlActivityEdge::inGroups(), QUmlElement::owner().

    \b {Opposite property(ies):} QUmlStructuredActivityNode::edges().
 */
QUmlStructuredActivityNode *QUmlActivityEdge::inStructuredNode() const
{
    // This is a read-write association end

    return _inStructuredNode;
}

/*!
    Adjusts inStructuredNode to \a inStructuredNode.
 */
void QUmlActivityEdge::setInStructuredNode(QUmlStructuredActivityNode *inStructuredNode)
{
    // This is a read-write association end

    if (_inStructuredNode != inStructuredNode) {
        // Adjust subsetted properties
        removeInGroup(_inStructuredNode);

        _inStructuredNode = inStructuredNode;
        if (inStructuredNode && inStructuredNode->asQModelingObject() && this->asQModelingObject())
            QObject::connect(inStructuredNode->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setInStructuredNode()));

        // Adjust subsetted properties
        if (inStructuredNode) {
            addInGroup(inStructuredNode);
        }
        setOwner(inStructuredNode);
    }
}

/*!
    Region that the edge can interrupt.

    \b {Opposite property(ies):} QUmlInterruptibleActivityRegion::interruptingEdges().
 */
QUmlInterruptibleActivityRegion *QUmlActivityEdge::interrupts() const
{
    // This is a read-write association end

    return _interrupts;
}

/*!
    Adjusts interrupts to \a interrupts.
 */
void QUmlActivityEdge::setInterrupts(QUmlInterruptibleActivityRegion *interrupts)
{
    // This is a read-write association end

    if (_interrupts != interrupts) {
        _interrupts = interrupts;
        if (interrupts && interrupts->asQModelingObject() && this->asQModelingObject())
            QObject::connect(interrupts->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setInterrupts()));
    }
}

/*!
    Inherited edges replaced by this edge in a specialization of the activity.

    \sa addRedefinedEdge(), removeRedefinedEdge()

    \b {Subsetted property(ies):} QUmlRedefinableElement::redefinedElements().
 */
const QSet<QUmlActivityEdge *> QUmlActivityEdge::redefinedEdges() const
{
    // This is a read-write association end

    return _redefinedEdges;
}

/*!
    Adds \a redefinedEdge to redefinedEdges.

    \sa redefinedEdges(), removeRedefinedEdge()
 */
void QUmlActivityEdge::addRedefinedEdge(QUmlActivityEdge *redefinedEdge)
{
    // This is a read-write association end

    if (!_redefinedEdges.contains(redefinedEdge)) {
        _redefinedEdges.insert(redefinedEdge);
        if (redefinedEdge && redefinedEdge->asQModelingObject() && this->asQModelingObject())
            QObject::connect(redefinedEdge->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeRedefinedEdge(QObject *)));

        // Adjust subsetted properties
        addRedefinedElement(redefinedEdge);
    }
}

/*!
    Removes \a redefinedEdge from redefinedEdges.

    \sa redefinedEdges(), addRedefinedEdge()
 */
void QUmlActivityEdge::removeRedefinedEdge(QUmlActivityEdge *redefinedEdge)
{
    // This is a read-write association end

    if (_redefinedEdges.contains(redefinedEdge)) {
        _redefinedEdges.remove(redefinedEdge);

        // Adjust subsetted properties
        removeRedefinedElement(redefinedEdge);
    }
}

/*!
    Node from which tokens are taken when they traverse the edge.

    \b {Opposite property(ies):} QUmlActivityNode::outgoings().
 */
QUmlActivityNode *QUmlActivityEdge::source() const
{
    // This is a read-write association end

    return _source;
}

/*!
    Adjusts source to \a source.
 */
void QUmlActivityEdge::setSource(QUmlActivityNode *source)
{
    // This is a read-write association end

    if (_source != source) {
        _source = source;
        if (source && source->asQModelingObject() && this->asQModelingObject())
            QObject::connect(source->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setSource()));
    }
}

/*!
    Node to which tokens are put when they traverse the edge.

    \b {Opposite property(ies):} QUmlActivityNode::incomings().
 */
QUmlActivityNode *QUmlActivityEdge::target() const
{
    // This is a read-write association end

    return _target;
}

/*!
    Adjusts target to \a target.
 */
void QUmlActivityEdge::setTarget(QUmlActivityNode *target)
{
    // This is a read-write association end

    if (_target != target) {
        _target = target;
        if (target && target->asQModelingObject() && this->asQModelingObject())
            QObject::connect(target->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setTarget()));
    }
}

/*!
    The minimum number of tokens that must traverse the edge at the same time.

    \b {Subsetted property(ies):} QUmlElement::ownedElements().
 */
QUmlValueSpecification *QUmlActivityEdge::weight() const
{
    // This is a read-write association end

    return _weight;
}

/*!
    Adjusts weight to \a weight.
 */
void QUmlActivityEdge::setWeight(QUmlValueSpecification *weight)
{
    // This is a read-write association end

    if (_weight != weight) {
        // Adjust subsetted properties
        removeOwnedElement(_weight);

        _weight = weight;
        if (weight && weight->asQModelingObject() && this->asQModelingObject())
            QObject::connect(weight->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setWeight()));
        weight->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        if (weight) {
            addOwnedElement(weight);
        }
    }
}

QT_END_NAMESPACE

