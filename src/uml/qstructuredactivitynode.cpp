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

#include "qstructuredactivitynode.h"
#include "qstructuredactivitynode_p.h"

#include <QtUml/QOutputPin>
#include <QtUml/QVariable>
#include <QtUml/QInputPin>
#include <QtUml/QActivityEdge>
#include <QtUml/QActivity>
#include <QtUml/QActivityNode>

QT_BEGIN_NAMESPACE_QTUML

QStructuredActivityNodePrivate::QStructuredActivityNodePrivate() :
    mustIsolate(false),
    structuredNodeInputs(new QSet<QInputPin *>),
    nodes(new QSet<QActivityNode *>),
    structuredNodeOutputs(new QSet<QOutputPin *>),
    edges(new QSet<QActivityEdge *>),
    variables(new QSet<QVariable *>),
    activity(0)
{
}

QStructuredActivityNodePrivate::~QStructuredActivityNodePrivate()
{
    delete structuredNodeInputs;
    delete nodes;
    delete structuredNodeOutputs;
    delete edges;
    delete variables;
}

/*!
    \class QStructuredActivityNode

    \inmodule QtUml

    \brief A structured activity node is an executable activity node that may have an expansion into subordinate nodes as an activity group. The subordinate nodes must belong to only one structured activity node, although they may be nested.Because of the concurrent nature of the execution of actions within and across activities, it can be difficult to guarantee the consistent access and modification of object memory. In order to avoid race conditions or other concurrency-related problems, it is sometimes necessary to isolate the effects of a group of actions from the effects of actions outside the group. This may be indicated by setting the mustIsolate attribute to true on a structured activity node. If a structured activity node is "isolated," then any object used by an action within the node cannot be accessed by any action outside the node until the structured activity node as a whole completes. Any concurrent actions that would result in accessing such objects are required to have their execution deferred until the completion of the node.
 */

QStructuredActivityNode::QStructuredActivityNode(QObject *parent) :
    QObject(*new QStructuredActivityNodePrivate, parent),
    _wrappedAction(new QAction(this)),
    _wrappedNamespace(new QNamespace(this)),
    _wrappedActivityGroup(new QActivityGroup(this))
{
    qRegisterMetaType<QStructuredActivityNode *>("QStructuredActivityNode *");
    qRegisterMetaType<const QSet<QStructuredActivityNode *> *>("const QSet<QStructuredActivityNode *> *");
    qRegisterMetaType<const QList<QStructuredActivityNode *> *>("const QList<QStructuredActivityNode *> *");
}

QStructuredActivityNode::QStructuredActivityNode(QStructuredActivityNodePrivate &dd, QObject *parent) :
    QObject(dd, parent),
    _wrappedAction(new QAction(this)),
    _wrappedNamespace(new QNamespace(this)),
    _wrappedActivityGroup(new QActivityGroup(this))
{
    qRegisterMetaType<QStructuredActivityNode *>("QStructuredActivityNode *");
    qRegisterMetaType<const QSet<QStructuredActivityNode *> *>("const QSet<QStructuredActivityNode *> *");
    qRegisterMetaType<const QList<QStructuredActivityNode *> *>("const QList<QStructuredActivityNode *> *");
}

QStructuredActivityNode::~QStructuredActivityNode()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QElement
// ---------------------------------------------------------------

/*!
    The Elements owned by this element.
 */
const QSet<QElement *> *QStructuredActivityNode::ownedElements() const
{
    return (qtuml_object_cast<const QElement *>(this))->ownedElements();
}

/*!
    The Element that owns this element.
 */
QElement *QStructuredActivityNode::owner() const
{
    return (qtuml_object_cast<const QElement *>(this))->owner();
}

/*!
    The Comments owned by this element.
 */
const QSet<QComment *> *QStructuredActivityNode::ownedComments() const
{
    return (qtuml_object_cast<const QElement *>(this))->ownedComments();
}

void QStructuredActivityNode::addOwnedComment(QComment *ownedComment)
{
    (qtuml_object_cast<QElement *>(this))->addOwnedComment(ownedComment);
}

void QStructuredActivityNode::removeOwnedComment(QComment *ownedComment)
{
    (qtuml_object_cast<QElement *>(this))->removeOwnedComment(ownedComment);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The name of the NamedElement.
 */
QString QStructuredActivityNode::name() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->name();
}

void QStructuredActivityNode::setName(QString name)
{
    (qtuml_object_cast<QNamedElement *>(this))->setName(name);
}

/*!
    Determines where the NamedElement appears within different Namespaces within the overall model, and its accessibility.
 */
QtUml::VisibilityKind QStructuredActivityNode::visibility() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->visibility();
}

void QStructuredActivityNode::setVisibility(QtUml::VisibilityKind visibility)
{
    (qtuml_object_cast<QNamedElement *>(this))->setVisibility(visibility);
}

/*!
    A name which allows the NamedElement to be identified within a hierarchy of nested Namespaces. It is constructed from the names of the containing namespaces starting at the root of the hierarchy and ending with the name of the NamedElement itself.
 */
QString QStructuredActivityNode::qualifiedName() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->qualifiedName();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The string expression used to define the name of this named element.
 */
QStringExpression *QStructuredActivityNode::nameExpression() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->nameExpression();
}

void QStructuredActivityNode::setNameExpression(QStringExpression *nameExpression)
{
    (qtuml_object_cast<QNamedElement *>(this))->setNameExpression(nameExpression);
}

/*!
    Specifies the namespace that owns the NamedElement.
 */
QNamespace *QStructuredActivityNode::namespace_() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->namespace_();
}

/*!
    Indicates the dependencies that reference the client.
 */
const QSet<QDependency *> *QStructuredActivityNode::clientDependencies() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->clientDependencies();
}

void QStructuredActivityNode::addClientDependency(QDependency *clientDependency)
{
    (qtuml_object_cast<QNamedElement *>(this))->addClientDependency(clientDependency);
}

void QStructuredActivityNode::removeClientDependency(QDependency *clientDependency)
{
    (qtuml_object_cast<QNamedElement *>(this))->removeClientDependency(clientDependency);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QRedefinableElement
// ---------------------------------------------------------------

/*!
    Indicates whether it is possible to further redefine a RedefinableElement. If the value is true, then it is not possible to further redefine the RedefinableElement. Note that this property is preserved through package merge operations; that is, the capability to redefine a RedefinableElement (i.e., isLeaf=false) must be preserved in the resulting RedefinableElement of a package merge operation where a RedefinableElement with isLeaf=false is merged with a matching RedefinableElement with isLeaf=true: the resulting RedefinableElement will have isLeaf=false. Default value is false.
 */
bool QStructuredActivityNode::isLeaf() const
{
    return (qtuml_object_cast<const QRedefinableElement *>(this))->isLeaf();
}

void QStructuredActivityNode::setLeaf(bool isLeaf)
{
    (qtuml_object_cast<QRedefinableElement *>(this))->setLeaf(isLeaf);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QRedefinableElement
// ---------------------------------------------------------------

/*!
    The redefinable element that is being redefined by this element.
 */
const QSet<QRedefinableElement *> *QStructuredActivityNode::redefinedElements() const
{
    return (qtuml_object_cast<const QRedefinableElement *>(this))->redefinedElements();
}

/*!
    References the contexts that this element may be redefined from.
 */
const QSet<QClassifier *> *QStructuredActivityNode::redefinitionContexts() const
{
    return (qtuml_object_cast<const QRedefinableElement *>(this))->redefinitionContexts();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QActivityNode
// ---------------------------------------------------------------

/*!
    Inherited nodes replaced by this node in a specialization of the activity.
 */
const QSet<QActivityNode *> *QStructuredActivityNode::redefinedNodes() const
{
    return (qtuml_object_cast<const QActivityNode *>(this))->redefinedNodes();
}

void QStructuredActivityNode::addRedefinedNode(QActivityNode *redefinedNode)
{
    (qtuml_object_cast<QActivityNode *>(this))->addRedefinedNode(redefinedNode);
}

void QStructuredActivityNode::removeRedefinedNode(QActivityNode *redefinedNode)
{
    (qtuml_object_cast<QActivityNode *>(this))->removeRedefinedNode(redefinedNode);
}

/*!
    Edges that have the node as target.
 */
const QSet<QActivityEdge *> *QStructuredActivityNode::incomings() const
{
    return (qtuml_object_cast<const QActivityNode *>(this))->incomings();
}

void QStructuredActivityNode::addIncoming(QActivityEdge *incoming)
{
    (qtuml_object_cast<QActivityNode *>(this))->addIncoming(incoming);
}

void QStructuredActivityNode::removeIncoming(QActivityEdge *incoming)
{
    (qtuml_object_cast<QActivityNode *>(this))->removeIncoming(incoming);
}

/*!
    Groups containing the node.
 */
const QSet<QActivityGroup *> *QStructuredActivityNode::inGroup() const
{
    return (qtuml_object_cast<const QActivityNode *>(this))->inGroup();
}

/*!
    Structured activity node containing the node.
 */
QStructuredActivityNode *QStructuredActivityNode::inStructuredNode() const
{
    return (qtuml_object_cast<const QActivityNode *>(this))->inStructuredNode();
}

void QStructuredActivityNode::setInStructuredNode(QStructuredActivityNode *inStructuredNode)
{
    (qtuml_object_cast<QActivityNode *>(this))->setInStructuredNode(inStructuredNode);
}

/*!
    Partitions containing the node.
 */
const QSet<QActivityPartition *> *QStructuredActivityNode::inPartition() const
{
    return (qtuml_object_cast<const QActivityNode *>(this))->inPartition();
}

void QStructuredActivityNode::addInPartition(QActivityPartition *inPartition)
{
    (qtuml_object_cast<QActivityNode *>(this))->addInPartition(inPartition);
}

void QStructuredActivityNode::removeInPartition(QActivityPartition *inPartition)
{
    (qtuml_object_cast<QActivityNode *>(this))->removeInPartition(inPartition);
}

/*!
    Interruptible regions containing the node.
 */
const QSet<QInterruptibleActivityRegion *> *QStructuredActivityNode::inInterruptibleRegion() const
{
    return (qtuml_object_cast<const QActivityNode *>(this))->inInterruptibleRegion();
}

void QStructuredActivityNode::addInInterruptibleRegion(QInterruptibleActivityRegion *inInterruptibleRegion)
{
    (qtuml_object_cast<QActivityNode *>(this))->addInInterruptibleRegion(inInterruptibleRegion);
}

void QStructuredActivityNode::removeInInterruptibleRegion(QInterruptibleActivityRegion *inInterruptibleRegion)
{
    (qtuml_object_cast<QActivityNode *>(this))->removeInInterruptibleRegion(inInterruptibleRegion);
}

/*!
    Edges that have the node as source.
 */
const QSet<QActivityEdge *> *QStructuredActivityNode::outgoings() const
{
    return (qtuml_object_cast<const QActivityNode *>(this))->outgoings();
}

void QStructuredActivityNode::addOutgoing(QActivityEdge *outgoing)
{
    (qtuml_object_cast<QActivityNode *>(this))->addOutgoing(outgoing);
}

void QStructuredActivityNode::removeOutgoing(QActivityEdge *outgoing)
{
    (qtuml_object_cast<QActivityNode *>(this))->removeOutgoing(outgoing);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QExecutableNode
// ---------------------------------------------------------------

/*!
    A set of exception handlers that are examined if an uncaught exception propagates to the outer level of the executable node.
 */
const QSet<QExceptionHandler *> *QStructuredActivityNode::handlers() const
{
    return (qtuml_object_cast<const QExecutableNode *>(this))->handlers();
}

void QStructuredActivityNode::addHandler(QExceptionHandler *handler)
{
    (qtuml_object_cast<QExecutableNode *>(this))->addHandler(handler);
}

void QStructuredActivityNode::removeHandler(QExceptionHandler *handler)
{
    (qtuml_object_cast<QExecutableNode *>(this))->removeHandler(handler);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QAction
// ---------------------------------------------------------------

/*!
    If true, the action can begin a new, concurrent execution, even if there is already another execution of the action ongoing. If false, the action cannot begin a new execution until any previous execution has completed.
 */
bool QStructuredActivityNode::isLocallyReentrant() const
{
    return (qtuml_object_cast<const QAction *>(this))->isLocallyReentrant();
}

void QStructuredActivityNode::setLocallyReentrant(bool isLocallyReentrant)
{
    (qtuml_object_cast<QAction *>(this))->setLocallyReentrant(isLocallyReentrant);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QAction
// ---------------------------------------------------------------

/*!
    The classifier that owns the behavior of which this action is a part.
 */
QClassifier *QStructuredActivityNode::context() const
{
    return (qtuml_object_cast<const QAction *>(this))->context();
}

/*!
    Constraint that must be satisfied when executed is completed.
 */
const QSet<QConstraint *> *QStructuredActivityNode::localPostconditions() const
{
    return (qtuml_object_cast<const QAction *>(this))->localPostconditions();
}

void QStructuredActivityNode::addLocalPostcondition(QConstraint *localPostcondition)
{
    (qtuml_object_cast<QAction *>(this))->addLocalPostcondition(localPostcondition);
}

void QStructuredActivityNode::removeLocalPostcondition(QConstraint *localPostcondition)
{
    (qtuml_object_cast<QAction *>(this))->removeLocalPostcondition(localPostcondition);
}

/*!
    Constraint that must be satisfied when execution is started.
 */
const QSet<QConstraint *> *QStructuredActivityNode::localPreconditions() const
{
    return (qtuml_object_cast<const QAction *>(this))->localPreconditions();
}

void QStructuredActivityNode::addLocalPrecondition(QConstraint *localPrecondition)
{
    (qtuml_object_cast<QAction *>(this))->addLocalPrecondition(localPrecondition);
}

void QStructuredActivityNode::removeLocalPrecondition(QConstraint *localPrecondition)
{
    (qtuml_object_cast<QAction *>(this))->removeLocalPrecondition(localPrecondition);
}

/*!
    The ordered set of input pins connected to the Action. These are among the total set of inputs.
 */
const QList<QInputPin *> *QStructuredActivityNode::inputs() const
{
    return (qtuml_object_cast<const QAction *>(this))->inputs();
}

/*!
    The ordered set of output pins connected to the Action. The action places its results onto pins in this set.
 */
const QList<QOutputPin *> *QStructuredActivityNode::outputs() const
{
    return (qtuml_object_cast<const QAction *>(this))->outputs();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamespace
// ---------------------------------------------------------------

/*!
    References the PackageImports owned by the Namespace.
 */
const QSet<QPackageImport *> *QStructuredActivityNode::packageImports() const
{
    return (qtuml_object_cast<const QNamespace *>(this))->packageImports();
}

void QStructuredActivityNode::addPackageImport(QPackageImport *packageImport)
{
    (qtuml_object_cast<QNamespace *>(this))->addPackageImport(packageImport);
}

void QStructuredActivityNode::removePackageImport(QPackageImport *packageImport)
{
    (qtuml_object_cast<QNamespace *>(this))->removePackageImport(packageImport);
}

/*!
    A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
 */
const QSet<QNamedElement *> *QStructuredActivityNode::members() const
{
    return (qtuml_object_cast<const QNamespace *>(this))->members();
}

/*!
    References the PackageableElements that are members of this Namespace as a result of either PackageImports or ElementImports.
 */
const QSet<QPackageableElement *> *QStructuredActivityNode::importedMembers() const
{
    return (qtuml_object_cast<const QNamespace *>(this))->importedMembers();
}

/*!
    References the ElementImports owned by the Namespace.
 */
const QSet<QElementImport *> *QStructuredActivityNode::elementImports() const
{
    return (qtuml_object_cast<const QNamespace *>(this))->elementImports();
}

void QStructuredActivityNode::addElementImport(QElementImport *elementImport)
{
    (qtuml_object_cast<QNamespace *>(this))->addElementImport(elementImport);
}

void QStructuredActivityNode::removeElementImport(QElementImport *elementImport)
{
    (qtuml_object_cast<QNamespace *>(this))->removeElementImport(elementImport);
}

/*!
    Specifies a set of Constraints owned by this Namespace.
 */
const QSet<QConstraint *> *QStructuredActivityNode::ownedRules() const
{
    return (qtuml_object_cast<const QNamespace *>(this))->ownedRules();
}

void QStructuredActivityNode::addOwnedRule(QConstraint *ownedRule)
{
    (qtuml_object_cast<QNamespace *>(this))->addOwnedRule(ownedRule);
}

void QStructuredActivityNode::removeOwnedRule(QConstraint *ownedRule)
{
    (qtuml_object_cast<QNamespace *>(this))->removeOwnedRule(ownedRule);
}

/*!
    A collection of NamedElements owned by the Namespace.
 */
const QSet<QNamedElement *> *QStructuredActivityNode::ownedMembers() const
{
    return (qtuml_object_cast<const QNamespace *>(this))->ownedMembers();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QActivityGroup
// ---------------------------------------------------------------

/*!
    Nodes immediately contained in the group.
 */
const QSet<QActivityNode *> *QStructuredActivityNode::containedNodes() const
{
    return (qtuml_object_cast<const QActivityGroup *>(this))->containedNodes();
}

/*!
    Groups immediately contained in the group.
 */
const QSet<QActivityGroup *> *QStructuredActivityNode::subgroups() const
{
    return (qtuml_object_cast<const QActivityGroup *>(this))->subgroups();
}

/*!
    Edges immediately contained in the group.
 */
const QSet<QActivityEdge *> *QStructuredActivityNode::containedEdges() const
{
    return (qtuml_object_cast<const QActivityGroup *>(this))->containedEdges();
}

/*!
    Group immediately containing the group.
 */
QActivityGroup *QStructuredActivityNode::superGroup() const
{
    return (qtuml_object_cast<const QActivityGroup *>(this))->superGroup();
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QStructuredActivityNode
// ---------------------------------------------------------------

/*!
    If true, then the actions in the node execute in isolation from actions outside the node.
 */
bool QStructuredActivityNode::mustIsolate() const
{
    // This is a read-write attribute

    Q_D(const QStructuredActivityNode);
    return d->mustIsolate;
}

void QStructuredActivityNode::setMustIsolate(bool mustIsolate)
{
    // This is a read-write attribute

    Q_D(QStructuredActivityNode);
    if (d->mustIsolate != mustIsolate) {
        d->mustIsolate = mustIsolate;
    }
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QStructuredActivityNode
// ---------------------------------------------------------------

const QSet<QInputPin *> *QStructuredActivityNode::structuredNodeInputs() const
{
    // This is a read-write association end

    Q_D(const QStructuredActivityNode);
    return d->structuredNodeInputs;
}

void QStructuredActivityNode::addStructuredNodeInput(QInputPin *structuredNodeInput)
{
    // This is a read-write association end

    Q_D(QStructuredActivityNode);
    if (!d->structuredNodeInputs->contains(structuredNodeInput)) {
        d->structuredNodeInputs->insert(structuredNodeInput);

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QActionPrivate *>(d))->addInput(qtuml_object_cast<QInputPin *>(structuredNodeInput));
    }
}

void QStructuredActivityNode::removeStructuredNodeInput(QInputPin *structuredNodeInput)
{
    // This is a read-write association end

    Q_D(QStructuredActivityNode);
    if (d->structuredNodeInputs->contains(structuredNodeInput)) {
        d->structuredNodeInputs->remove(structuredNodeInput);

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QActionPrivate *>(d))->removeInput(qtuml_object_cast<QInputPin *>(structuredNodeInput));
    }
}

/*!
    Nodes immediately contained in the group.
 */
const QSet<QActivityNode *> *QStructuredActivityNode::nodes() const
{
    // This is a read-write association end

    Q_D(const QStructuredActivityNode);
    return d->nodes;
}

void QStructuredActivityNode::addNode(QActivityNode *node)
{
    // This is a read-write association end

    Q_D(QStructuredActivityNode);
    if (!d->nodes->contains(node)) {
        d->nodes->insert(node);

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QActivityGroupPrivate *>(d))->addContainedNode(qtuml_object_cast<QActivityNode *>(node));
        (qtuml_object_cast<QElementPrivate *>(d))->addOwnedElement(qtuml_object_cast<QElement *>(node));

        // Adjust opposite property
        node->setInStructuredNode(this);
    }
}

void QStructuredActivityNode::removeNode(QActivityNode *node)
{
    // This is a read-write association end

    Q_D(QStructuredActivityNode);
    if (d->nodes->contains(node)) {
        d->nodes->remove(node);

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QActivityGroupPrivate *>(d))->removeContainedNode(qtuml_object_cast<QActivityNode *>(node));
        (qtuml_object_cast<QElementPrivate *>(d))->removeOwnedElement(qtuml_object_cast<QElement *>(node));

        // Adjust opposite property
        node->setInStructuredNode(0);
    }
}

const QSet<QOutputPin *> *QStructuredActivityNode::structuredNodeOutputs() const
{
    // This is a read-write association end

    Q_D(const QStructuredActivityNode);
    return d->structuredNodeOutputs;
}

void QStructuredActivityNode::addStructuredNodeOutput(QOutputPin *structuredNodeOutput)
{
    // This is a read-write association end

    Q_D(QStructuredActivityNode);
    if (!d->structuredNodeOutputs->contains(structuredNodeOutput)) {
        d->structuredNodeOutputs->insert(structuredNodeOutput);

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QActionPrivate *>(d))->addOutput(qtuml_object_cast<QOutputPin *>(structuredNodeOutput));
    }
}

void QStructuredActivityNode::removeStructuredNodeOutput(QOutputPin *structuredNodeOutput)
{
    // This is a read-write association end

    Q_D(QStructuredActivityNode);
    if (d->structuredNodeOutputs->contains(structuredNodeOutput)) {
        d->structuredNodeOutputs->remove(structuredNodeOutput);

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QActionPrivate *>(d))->removeOutput(qtuml_object_cast<QOutputPin *>(structuredNodeOutput));
    }
}

/*!
    Edges immediately contained in the structured node.
 */
const QSet<QActivityEdge *> *QStructuredActivityNode::edges() const
{
    // This is a read-write association end

    Q_D(const QStructuredActivityNode);
    return d->edges;
}

void QStructuredActivityNode::addEdge(QActivityEdge *edge)
{
    // This is a read-write association end

    Q_D(QStructuredActivityNode);
    if (!d->edges->contains(edge)) {
        d->edges->insert(edge);

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QActivityGroupPrivate *>(d))->addContainedEdge(qtuml_object_cast<QActivityEdge *>(edge));
        (qtuml_object_cast<QElementPrivate *>(d))->addOwnedElement(qtuml_object_cast<QElement *>(edge));

        // Adjust opposite property
        edge->setInStructuredNode(this);
    }
}

void QStructuredActivityNode::removeEdge(QActivityEdge *edge)
{
    // This is a read-write association end

    Q_D(QStructuredActivityNode);
    if (d->edges->contains(edge)) {
        d->edges->remove(edge);

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QActivityGroupPrivate *>(d))->removeContainedEdge(qtuml_object_cast<QActivityEdge *>(edge));
        (qtuml_object_cast<QElementPrivate *>(d))->removeOwnedElement(qtuml_object_cast<QElement *>(edge));

        // Adjust opposite property
        edge->setInStructuredNode(0);
    }
}

/*!
    A variable defined in the scope of the structured activity node. It has no value and may not be accessed
 */
const QSet<QVariable *> *QStructuredActivityNode::variables() const
{
    // This is a read-write association end

    Q_D(const QStructuredActivityNode);
    return d->variables;
}

void QStructuredActivityNode::addVariable(QVariable *variable)
{
    // This is a read-write association end

    Q_D(QStructuredActivityNode);
    if (!d->variables->contains(variable)) {
        d->variables->insert(variable);

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QNamespacePrivate *>(d))->addOwnedMember(qtuml_object_cast<QNamedElement *>(variable));

        // Adjust opposite property
        variable->setScope(this);
    }
}

void QStructuredActivityNode::removeVariable(QVariable *variable)
{
    // This is a read-write association end

    Q_D(QStructuredActivityNode);
    if (d->variables->contains(variable)) {
        d->variables->remove(variable);

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QNamespacePrivate *>(d))->removeOwnedMember(qtuml_object_cast<QNamedElement *>(variable));

        // Adjust opposite property
        variable->setScope(0);
    }
}

/*!
    Activity immediately containing the node.
 */
QActivity *QStructuredActivityNode::activity() const
{
    // This is a read-write association end

    Q_D(const QStructuredActivityNode);
    return d->activity;
}

void QStructuredActivityNode::setActivity(QActivity *activity)
{
    // This is a read-write association end

    Q_D(QStructuredActivityNode);
    if (d->activity != activity) {
        // Adjust opposite property
        if (d->activity)
            d->activity->removeStructuredNode(this);

        d->activity = activity;

        // Adjust opposite property
        if (activity)
            activity->addStructuredNode(this);
    }
}

#include "moc_qstructuredactivitynode.cpp"

QT_END_NAMESPACE_QTUML

