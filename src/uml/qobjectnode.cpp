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

#include "qobjectnode.h"
#include "qobjectnode_p.h"

#include <QtUml/QState>
#include <QtUml/QBehavior>
#include <QtUml/QValueSpecification>

QT_BEGIN_NAMESPACE_QTUML

QObjectNodePrivate::QObjectNodePrivate() :
    isControlType(false),
    ordering(QtUml::ObjectNodeOrderingFIFO),
    upperBound(0),
    selection(0),
    inState(new QSet<QState *>)
{
}

QObjectNodePrivate::~QObjectNodePrivate()
{
    delete inState;
}

/*!
    \class QObjectNode

    \inmodule QtUml

    \brief An object node is an abstract activity node that is part of defining object flow in an activity.Object nodes have support for token selection, limitation on the number of tokens, specifying the state required for tokens, and carrying control values.
 */

QObjectNode::QObjectNode(QWrappedObject *parent, QWrappedObject *wrapper) :
    QWrappedObject(*new QObjectNodePrivate, parent, wrapper),
    _wrappedActivityNode(new QActivityNode(this, this)),
    _wrappedTypedElement(new QTypedElement(this, this))
{
}

QObjectNode::QObjectNode(QObjectNodePrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QWrappedObject(dd, parent, wrapper),
    _wrappedActivityNode(new QActivityNode(this, this)),
    _wrappedTypedElement(new QTypedElement(this, this))
{
}

QObjectNode::~QObjectNode()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QElement
// ---------------------------------------------------------------

/*!
    The Elements owned by this element.
 */
const QSet<QElement *> *QObjectNode::ownedElements() const
{
    return (qwrappedobject_cast<const QElement *>(this))->ownedElements();
}

/*!
    The Element that owns this element.
 */
QElement *QObjectNode::owner() const
{
    return (qwrappedobject_cast<const QElement *>(this))->owner();
}

/*!
    The Comments owned by this element.
 */
const QSet<QComment *> *QObjectNode::ownedComments() const
{
    return (qwrappedobject_cast<const QElement *>(this))->ownedComments();
}

void QObjectNode::addOwnedComment(QComment *ownedComment)
{
    (qwrappedobject_cast<QElement *>(this))->addOwnedComment(ownedComment);
}

void QObjectNode::removeOwnedComment(QComment *ownedComment)
{
    (qwrappedobject_cast<QElement *>(this))->removeOwnedComment(ownedComment);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The name of the NamedElement.
 */
QString QObjectNode::name() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->name();
}

void QObjectNode::setName(QString name)
{
    (qwrappedobject_cast<QNamedElement *>(this))->setName(name);
}

/*!
    Determines where the NamedElement appears within different Namespaces within the overall model, and its accessibility.
 */
QtUml::VisibilityKind QObjectNode::visibility() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->visibility();
}

void QObjectNode::setVisibility(QtUml::VisibilityKind visibility)
{
    (qwrappedobject_cast<QNamedElement *>(this))->setVisibility(visibility);
}

/*!
    A name which allows the NamedElement to be identified within a hierarchy of nested Namespaces. It is constructed from the names of the containing namespaces starting at the root of the hierarchy and ending with the name of the NamedElement itself.
 */
QString QObjectNode::qualifiedName() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->qualifiedName();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The string expression used to define the name of this named element.
 */
QStringExpression *QObjectNode::nameExpression() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->nameExpression();
}

void QObjectNode::setNameExpression(QStringExpression *nameExpression)
{
    (qwrappedobject_cast<QNamedElement *>(this))->setNameExpression(nameExpression);
}

/*!
    Specifies the namespace that owns the NamedElement.
 */
QNamespace *QObjectNode::namespace_() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->namespace_();
}

/*!
    Indicates the dependencies that reference the client.
 */
const QSet<QDependency *> *QObjectNode::clientDependencies() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->clientDependencies();
}

void QObjectNode::addClientDependency(QDependency *clientDependency)
{
    (qwrappedobject_cast<QNamedElement *>(this))->addClientDependency(clientDependency);
}

void QObjectNode::removeClientDependency(QDependency *clientDependency)
{
    (qwrappedobject_cast<QNamedElement *>(this))->removeClientDependency(clientDependency);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QRedefinableElement
// ---------------------------------------------------------------

/*!
    Indicates whether it is possible to further redefine a RedefinableElement. If the value is true, then it is not possible to further redefine the RedefinableElement. Note that this property is preserved through package merge operations; that is, the capability to redefine a RedefinableElement (i.e., isLeaf=false) must be preserved in the resulting RedefinableElement of a package merge operation where a RedefinableElement with isLeaf=false is merged with a matching RedefinableElement with isLeaf=true: the resulting RedefinableElement will have isLeaf=false. Default value is false.
 */
bool QObjectNode::isLeaf() const
{
    return (qwrappedobject_cast<const QRedefinableElement *>(this))->isLeaf();
}

void QObjectNode::setLeaf(bool isLeaf)
{
    (qwrappedobject_cast<QRedefinableElement *>(this))->setLeaf(isLeaf);
}

void QObjectNode::unsetLeaf()
{
    setLeaf(false);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QRedefinableElement
// ---------------------------------------------------------------

/*!
    The redefinable element that is being redefined by this element.
 */
const QSet<QRedefinableElement *> *QObjectNode::redefinedElements() const
{
    return (qwrappedobject_cast<const QRedefinableElement *>(this))->redefinedElements();
}

/*!
    References the contexts that this element may be redefined from.
 */
const QSet<QClassifier *> *QObjectNode::redefinitionContexts() const
{
    return (qwrappedobject_cast<const QRedefinableElement *>(this))->redefinitionContexts();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QActivityNode
// ---------------------------------------------------------------

/*!
    Inherited nodes replaced by this node in a specialization of the activity.
 */
const QSet<QActivityNode *> *QObjectNode::redefinedNodes() const
{
    return (qwrappedobject_cast<const QActivityNode *>(this))->redefinedNodes();
}

void QObjectNode::addRedefinedNode(QActivityNode *redefinedNode)
{
    (qwrappedobject_cast<QActivityNode *>(this))->addRedefinedNode(redefinedNode);
}

void QObjectNode::removeRedefinedNode(QActivityNode *redefinedNode)
{
    (qwrappedobject_cast<QActivityNode *>(this))->removeRedefinedNode(redefinedNode);
}

/*!
    Edges that have the node as target.
 */
const QSet<QActivityEdge *> *QObjectNode::incomings() const
{
    return (qwrappedobject_cast<const QActivityNode *>(this))->incomings();
}

void QObjectNode::addIncoming(QActivityEdge *incoming)
{
    (qwrappedobject_cast<QActivityNode *>(this))->addIncoming(incoming);
}

void QObjectNode::removeIncoming(QActivityEdge *incoming)
{
    (qwrappedobject_cast<QActivityNode *>(this))->removeIncoming(incoming);
}

/*!
    Activity containing the node.
 */
QActivity *QObjectNode::activity() const
{
    return (qwrappedobject_cast<const QActivityNode *>(this))->activity();
}

void QObjectNode::setActivity(QActivity *activity)
{
    (qwrappedobject_cast<QActivityNode *>(this))->setActivity(activity);
}

/*!
    Groups containing the node.
 */
const QSet<QActivityGroup *> *QObjectNode::inGroup() const
{
    return (qwrappedobject_cast<const QActivityNode *>(this))->inGroup();
}

/*!
    Structured activity node containing the node.
 */
QStructuredActivityNode *QObjectNode::inStructuredNode() const
{
    return (qwrappedobject_cast<const QActivityNode *>(this))->inStructuredNode();
}

void QObjectNode::setInStructuredNode(QStructuredActivityNode *inStructuredNode)
{
    (qwrappedobject_cast<QActivityNode *>(this))->setInStructuredNode(inStructuredNode);
}

/*!
    Partitions containing the node.
 */
const QSet<QActivityPartition *> *QObjectNode::inPartition() const
{
    return (qwrappedobject_cast<const QActivityNode *>(this))->inPartition();
}

void QObjectNode::addInPartition(QActivityPartition *inPartition)
{
    (qwrappedobject_cast<QActivityNode *>(this))->addInPartition(inPartition);
}

void QObjectNode::removeInPartition(QActivityPartition *inPartition)
{
    (qwrappedobject_cast<QActivityNode *>(this))->removeInPartition(inPartition);
}

/*!
    Interruptible regions containing the node.
 */
const QSet<QInterruptibleActivityRegion *> *QObjectNode::inInterruptibleRegion() const
{
    return (qwrappedobject_cast<const QActivityNode *>(this))->inInterruptibleRegion();
}

void QObjectNode::addInInterruptibleRegion(QInterruptibleActivityRegion *inInterruptibleRegion)
{
    (qwrappedobject_cast<QActivityNode *>(this))->addInInterruptibleRegion(inInterruptibleRegion);
}

void QObjectNode::removeInInterruptibleRegion(QInterruptibleActivityRegion *inInterruptibleRegion)
{
    (qwrappedobject_cast<QActivityNode *>(this))->removeInInterruptibleRegion(inInterruptibleRegion);
}

/*!
    Edges that have the node as source.
 */
const QSet<QActivityEdge *> *QObjectNode::outgoings() const
{
    return (qwrappedobject_cast<const QActivityNode *>(this))->outgoings();
}

void QObjectNode::addOutgoing(QActivityEdge *outgoing)
{
    (qwrappedobject_cast<QActivityNode *>(this))->addOutgoing(outgoing);
}

void QObjectNode::removeOutgoing(QActivityEdge *outgoing)
{
    (qwrappedobject_cast<QActivityNode *>(this))->removeOutgoing(outgoing);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QTypedElement
// ---------------------------------------------------------------

/*!
    This information is derived from the return result for this Operation.The type of the TypedElement.
 */
QType *QObjectNode::type() const
{
    return (qwrappedobject_cast<const QTypedElement *>(this))->type();
}

void QObjectNode::setType(QType *type)
{
    (qwrappedobject_cast<QTypedElement *>(this))->setType(type);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QObjectNode
// ---------------------------------------------------------------

/*!
    Tells whether the type of the object node is to be treated as control.
 */
bool QObjectNode::isControlType() const
{
    // This is a read-write attribute

    Q_D(const QObjectNode);
    return d->isControlType;
}

void QObjectNode::setControlType(bool isControlType)
{
    // This is a read-write attribute

    Q_D(QObjectNode);
    if (d->isControlType != isControlType) {
        d->isControlType = isControlType;
    }
}

void QObjectNode::unsetControlType()
{
    setControlType(false);
}

/*!
    Tells whether and how the tokens in the object node are ordered for selection to traverse edges outgoing from the object node.
 */
QtUml::ObjectNodeOrderingKind QObjectNode::ordering() const
{
    // This is a read-write attribute

    Q_D(const QObjectNode);
    return d->ordering;
}

void QObjectNode::setOrdering(QtUml::ObjectNodeOrderingKind ordering)
{
    // This is a read-write attribute

    Q_D(QObjectNode);
    if (d->ordering != ordering) {
        d->ordering = ordering;
    }
}

void QObjectNode::unsetOrdering()
{
    setOrdering(QtUml::ObjectNodeOrderingFIFO);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QObjectNode
// ---------------------------------------------------------------

/*!
    The maximum number of tokens allowed in the node. Objects cannot flow into the node if the upper bound is reached.
 */
QValueSpecification *QObjectNode::upperBound() const
{
    // This is a read-write association end

    Q_D(const QObjectNode);
    return d->upperBound;
}

void QObjectNode::setUpperBound(QValueSpecification *upperBound)
{
    // This is a read-write association end

    Q_D(QObjectNode);
    if (d->upperBound != upperBound) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QElement *>(d->upperBound));

        d->upperBound = upperBound;

        // Adjust subsetted property(ies)
        if (upperBound) {
            (qwrappedobject_cast<QElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QElement *>(upperBound));
        }
    }
}

/*!
    Selects tokens for outgoing edges.
 */
QBehavior *QObjectNode::selection() const
{
    // This is a read-write association end

    Q_D(const QObjectNode);
    return d->selection;
}

void QObjectNode::setSelection(QBehavior *selection)
{
    // This is a read-write association end

    Q_D(QObjectNode);
    if (d->selection != selection) {
        d->selection = selection;
    }
}

/*!
    The required states of the object available at this point in the activity.
 */
const QSet<QState *> *QObjectNode::inState() const
{
    // This is a read-write association end

    Q_D(const QObjectNode);
    return d->inState;
}

void QObjectNode::addInState(QState *inState)
{
    // This is a read-write association end

    Q_D(QObjectNode);
    if (!d->inState->contains(inState)) {
        d->inState->insert(inState);
    }
}

void QObjectNode::removeInState(QState *inState)
{
    // This is a read-write association end

    Q_D(QObjectNode);
    if (d->inState->contains(inState)) {
        d->inState->remove(inState);
    }
}

void QObjectNode::registerMetaTypes() const
{
    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QObjectNode) *>("QT_PREPEND_NAMESPACE_QTUML(QObjectNode) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QObjectNode) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QObjectNode) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QObjectNode) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QObjectNode) *> *");
    qRegisterMetaType<QObjectNode *>("QObjectNode *");
    qRegisterMetaType<const QSet<QObjectNode *> *>("const QSet<QObjectNode *> *");
    qRegisterMetaType<const QList<QObjectNode *> *>("const QList<QObjectNode *> *");

    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QState) *>("QT_PREPEND_NAMESPACE_QTUML(QState) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QState) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QState) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QState) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QState) *> *");
    qRegisterMetaType<QState *>("QState *");
    qRegisterMetaType<const QSet<QState *> *>("const QSet<QState *> *");
    qRegisterMetaType<const QList<QState *> *>("const QList<QState *> *");

    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QBehavior) *>("QT_PREPEND_NAMESPACE_QTUML(QBehavior) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QBehavior) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QBehavior) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QBehavior) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QBehavior) *> *");
    qRegisterMetaType<QBehavior *>("QBehavior *");
    qRegisterMetaType<const QSet<QBehavior *> *>("const QSet<QBehavior *> *");
    qRegisterMetaType<const QList<QBehavior *> *>("const QList<QBehavior *> *");

    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QValueSpecification) *>("QT_PREPEND_NAMESPACE_QTUML(QValueSpecification) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QValueSpecification) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QValueSpecification) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QValueSpecification) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QValueSpecification) *> *");
    qRegisterMetaType<QValueSpecification *>("QValueSpecification *");
    qRegisterMetaType<const QSet<QValueSpecification *> *>("const QSet<QValueSpecification *> *");
    qRegisterMetaType<const QList<QValueSpecification *> *>("const QList<QValueSpecification *> *");

    QWrappedObject::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qobjectnode.cpp"

QT_END_NAMESPACE_QTUML

