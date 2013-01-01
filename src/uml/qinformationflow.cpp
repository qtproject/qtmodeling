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

#include "qinformationflow.h"
#include "qinformationflow_p.h"

#include <QtUml/QConnector>
#include <QtUml/QMessage>
#include <QtUml/QActivityEdge>
#include <QtUml/QNamedElement>
#include <QtUml/QClassifier>
#include <QtUml/QRelationship>

#include <QtWrappedObjects/QtWrappedObjectsEnumerations>

QT_BEGIN_NAMESPACE_QTUML

QInformationFlowPrivate::QInformationFlowPrivate()
{
}

QInformationFlowPrivate::~QInformationFlowPrivate()
{
}

/*!
    \class QInformationFlow

    \inmodule QtUml

    \brief An information flow specifies that one or more information items circulates from its sources to its targets. Information flows require some kind of information channel for transmitting information items from the source to the destination. An information channel is represented in various ways depending on the nature of its sources and targets. It may be represented by connectors, links, associations, or even dependencies. For example, if the source and destination are parts in some composite structure such as a collaboration, then the information channel is likely to be represented by a connector between them. Or, if the source and target are objects (which are a kind of instance specification), they may be represented by a link that joins the two, and so on.
 */

QInformationFlow::QInformationFlow(QWrappedObject *parent, QWrappedObject *wrapper) :
    QWrappedObject(*new QInformationFlowPrivate, parent, wrapper),
    _wrappedDirectedRelationship(new QDirectedRelationship(this, this)),
    _wrappedPackageableElement(new QPackageableElement(this, this))
{
    setPropertyData();
}

QInformationFlow::QInformationFlow(QInformationFlowPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QWrappedObject(dd, parent, wrapper),
    _wrappedDirectedRelationship(new QDirectedRelationship(this, this)),
    _wrappedPackageableElement(new QPackageableElement(this, this))
{
    setPropertyData();
}

QInformationFlow::~QInformationFlow()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QElement
// ---------------------------------------------------------------

/*!
    The Elements owned by this element.
 */
QSet<QElement *> QInformationFlow::ownedElements() const
{
    return (qwrappedobject_cast<const QElement *>(this))->ownedElements();
}

/*!
    The Element that owns this element.
 */
QElement *QInformationFlow::owner() const
{
    return (qwrappedobject_cast<const QElement *>(this))->owner();
}

/*!
    The Comments owned by this element.
 */
QSet<QComment *> QInformationFlow::ownedComments() const
{
    return (qwrappedobject_cast<const QElement *>(this))->ownedComments();
}

void QInformationFlow::addOwnedComment(QComment *ownedComment)
{
    (qwrappedobject_cast<QElement *>(this))->addOwnedComment(ownedComment);
}

void QInformationFlow::removeOwnedComment(QComment *ownedComment)
{
    (qwrappedobject_cast<QElement *>(this))->removeOwnedComment(ownedComment);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QRelationship
// ---------------------------------------------------------------

/*!
    Specifies the elements related by the Relationship.
 */
QSet<QElement *> QInformationFlow::relatedElements() const
{
    return (qwrappedobject_cast<const QRelationship *>(this))->relatedElements();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QDirectedRelationship
// ---------------------------------------------------------------

/*!
    Specifies the sources of the DirectedRelationship.
 */
QSet<QElement *> QInformationFlow::sources() const
{
    return (qwrappedobject_cast<const QDirectedRelationship *>(this))->sources();
}

/*!
    Specifies the targets of the DirectedRelationship.
 */
QSet<QElement *> QInformationFlow::targets() const
{
    return (qwrappedobject_cast<const QDirectedRelationship *>(this))->targets();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QParameterableElement
// ---------------------------------------------------------------

/*!
    The formal template parameter that owns this element.
 */
QTemplateParameter *QInformationFlow::owningTemplateParameter() const
{
    return (qwrappedobject_cast<const QParameterableElement *>(this))->owningTemplateParameter();
}

void QInformationFlow::setOwningTemplateParameter(QTemplateParameter *owningTemplateParameter)
{
    (qwrappedobject_cast<QParameterableElement *>(this))->setOwningTemplateParameter(owningTemplateParameter);
}

/*!
    The template parameter that exposes this element as a formal parameter.
 */
QTemplateParameter *QInformationFlow::templateParameter() const
{
    return (qwrappedobject_cast<const QParameterableElement *>(this))->templateParameter();
}

void QInformationFlow::setTemplateParameter(QTemplateParameter *templateParameter)
{
    (qwrappedobject_cast<QParameterableElement *>(this))->setTemplateParameter(templateParameter);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The name of the NamedElement.
 */
QString QInformationFlow::name() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->name();
}

void QInformationFlow::setName(QString name)
{
    (qwrappedobject_cast<QNamedElement *>(this))->setName(name);
}

/*!
    A name which allows the NamedElement to be identified within a hierarchy of nested Namespaces. It is constructed from the names of the containing namespaces starting at the root of the hierarchy and ending with the name of the NamedElement itself.
 */
QString QInformationFlow::qualifiedName() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->qualifiedName();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The string expression used to define the name of this named element.
 */
QStringExpression *QInformationFlow::nameExpression() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->nameExpression();
}

void QInformationFlow::setNameExpression(QStringExpression *nameExpression)
{
    (qwrappedobject_cast<QNamedElement *>(this))->setNameExpression(nameExpression);
}

/*!
    Specifies the namespace that owns the NamedElement.
 */
QNamespace *QInformationFlow::namespace_() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->namespace_();
}

/*!
    Indicates the dependencies that reference the client.
 */
QSet<QDependency *> QInformationFlow::clientDependencies() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->clientDependencies();
}

void QInformationFlow::addClientDependency(QDependency *clientDependency)
{
    (qwrappedobject_cast<QNamedElement *>(this))->addClientDependency(clientDependency);
}

void QInformationFlow::removeClientDependency(QDependency *clientDependency)
{
    (qwrappedobject_cast<QNamedElement *>(this))->removeClientDependency(clientDependency);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QPackageableElement
// ---------------------------------------------------------------

/*!
    Indicates that packageable elements must always have a visibility, i.e., visibility is not optional.
 */
QtUml::VisibilityKind QInformationFlow::visibility() const
{
    return (qwrappedobject_cast<const QPackageableElement *>(this))->visibility();
}

void QInformationFlow::setVisibility(QtUml::VisibilityKind visibility)
{
    (qwrappedobject_cast<QPackageableElement *>(this))->setVisibility(visibility);
}

void QInformationFlow::unsetVisibility()
{
    setVisibility(QtUml::VisibilityPublic);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QInformationFlow
// ---------------------------------------------------------------

/*!
    Defines to which target the conveyed InformationItems are directed.
 */
QSet<QNamedElement *> QInformationFlow::informationTargets() const
{
    // This is a read-write association end

    Q_D(const QInformationFlow);
    return d->informationTargets;
}

void QInformationFlow::addInformationTarget(QNamedElement *informationTarget)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (!d->informationTargets.contains(informationTarget)) {
        d->informationTargets.insert(informationTarget);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QDirectedRelationshipPrivate *>(d))->addTarget(qwrappedobject_cast<QElement *>(informationTarget));
    }
}

void QInformationFlow::removeInformationTarget(QNamedElement *informationTarget)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (d->informationTargets.contains(informationTarget)) {
        d->informationTargets.remove(informationTarget);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QDirectedRelationshipPrivate *>(d))->removeTarget(qwrappedobject_cast<QElement *>(informationTarget));
    }
}

/*!
    Determines which Connectors will realize the specified flow.
 */
QSet<QConnector *> QInformationFlow::realizingConnectors() const
{
    // This is a read-write association end

    Q_D(const QInformationFlow);
    return d->realizingConnectors;
}

void QInformationFlow::addRealizingConnector(QConnector *realizingConnector)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (!d->realizingConnectors.contains(realizingConnector)) {
        d->realizingConnectors.insert(realizingConnector);
    }
}

void QInformationFlow::removeRealizingConnector(QConnector *realizingConnector)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (d->realizingConnectors.contains(realizingConnector)) {
        d->realizingConnectors.remove(realizingConnector);
    }
}

/*!
    Specifies the information items that may circulate on this information flow.
 */
QSet<QClassifier *> QInformationFlow::conveyed() const
{
    // This is a read-write association end

    Q_D(const QInformationFlow);
    return d->conveyed;
}

void QInformationFlow::addConveyed(QClassifier *conveyed)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (!d->conveyed.contains(conveyed)) {
        d->conveyed.insert(conveyed);
    }
}

void QInformationFlow::removeConveyed(QClassifier *conveyed)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (d->conveyed.contains(conveyed)) {
        d->conveyed.remove(conveyed);
    }
}

/*!
    Defines from which source the conveyed InformationItems are initiated.
 */
QSet<QNamedElement *> QInformationFlow::informationSources() const
{
    // This is a read-write association end

    Q_D(const QInformationFlow);
    return d->informationSources;
}

void QInformationFlow::addInformationSource(QNamedElement *informationSource)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (!d->informationSources.contains(informationSource)) {
        d->informationSources.insert(informationSource);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QDirectedRelationshipPrivate *>(d))->addSource(qwrappedobject_cast<QElement *>(informationSource));
    }
}

void QInformationFlow::removeInformationSource(QNamedElement *informationSource)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (d->informationSources.contains(informationSource)) {
        d->informationSources.remove(informationSource);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QDirectedRelationshipPrivate *>(d))->removeSource(qwrappedobject_cast<QElement *>(informationSource));
    }
}

/*!
    Determines which Messages will realize the specified flow.
 */
QSet<QMessage *> QInformationFlow::realizingMessages() const
{
    // This is a read-write association end

    Q_D(const QInformationFlow);
    return d->realizingMessages;
}

void QInformationFlow::addRealizingMessage(QMessage *realizingMessage)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (!d->realizingMessages.contains(realizingMessage)) {
        d->realizingMessages.insert(realizingMessage);
    }
}

void QInformationFlow::removeRealizingMessage(QMessage *realizingMessage)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (d->realizingMessages.contains(realizingMessage)) {
        d->realizingMessages.remove(realizingMessage);
    }
}

/*!
    Determines which ActivityEdges will realize the specified flow.
 */
QSet<QActivityEdge *> QInformationFlow::realizingActivityEdges() const
{
    // This is a read-write association end

    Q_D(const QInformationFlow);
    return d->realizingActivityEdges;
}

void QInformationFlow::addRealizingActivityEdge(QActivityEdge *realizingActivityEdge)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (!d->realizingActivityEdges.contains(realizingActivityEdge)) {
        d->realizingActivityEdges.insert(realizingActivityEdge);
    }
}

void QInformationFlow::removeRealizingActivityEdge(QActivityEdge *realizingActivityEdge)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (d->realizingActivityEdges.contains(realizingActivityEdge)) {
        d->realizingActivityEdges.remove(realizingActivityEdge);
    }
}

/*!
    Determines which Relationship will realize the specified flow
 */
QSet<QRelationship *> QInformationFlow::realizations() const
{
    // This is a read-write association end

    Q_D(const QInformationFlow);
    return d->realizations;
}

void QInformationFlow::addRealization(QRelationship *realization)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (!d->realizations.contains(realization)) {
        d->realizations.insert(realization);
    }
}

void QInformationFlow::removeRealization(QRelationship *realization)
{
    // This is a read-write association end

    Q_D(QInformationFlow);
    if (d->realizations.contains(realization)) {
        d->realizations.remove(realization);
    }
}

void QInformationFlow::registerMetaTypes() const
{
    qRegisterMetaType<QConnector *>("QConnector *");
    qRegisterMetaType<QSet<QConnector *>>("QSet<QConnector *>");
    qRegisterMetaType<QList<QConnector *>>("QList<QConnector *>");

    qRegisterMetaType<QMessage *>("QMessage *");
    qRegisterMetaType<QSet<QMessage *>>("QSet<QMessage *>");
    qRegisterMetaType<QList<QMessage *>>("QList<QMessage *>");

    qRegisterMetaType<QActivityEdge *>("QActivityEdge *");
    qRegisterMetaType<QSet<QActivityEdge *>>("QSet<QActivityEdge *>");
    qRegisterMetaType<QList<QActivityEdge *>>("QList<QActivityEdge *>");

    qRegisterMetaType<QNamedElement *>("QNamedElement *");
    qRegisterMetaType<QSet<QNamedElement *>>("QSet<QNamedElement *>");
    qRegisterMetaType<QList<QNamedElement *>>("QList<QNamedElement *>");

    qRegisterMetaType<QClassifier *>("QClassifier *");
    qRegisterMetaType<QSet<QClassifier *>>("QSet<QClassifier *>");
    qRegisterMetaType<QList<QClassifier *>>("QList<QClassifier *>");

    qRegisterMetaType<QRelationship *>("QRelationship *");
    qRegisterMetaType<QSet<QRelationship *>>("QSet<QRelationship *>");
    qRegisterMetaType<QList<QRelationship *>>("QList<QRelationship *>");

    QWrappedObject::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

void QInformationFlow::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("informationTargets")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("informationTargets")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("informationTargets")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Defines to which target the conveyed InformationItems are directed.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("informationTargets")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("informationTargets")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QDirectedRelationship::target");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingConnectors")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingConnectors")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingConnectors")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Determines which Connectors will realize the specified flow.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingConnectors")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingConnectors")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("conveyed")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("conveyed")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("conveyed")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Specifies the information items that may circulate on this information flow.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("conveyed")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("conveyed")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("informationSources")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("informationSources")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("informationSources")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Defines from which source the conveyed InformationItems are initiated.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("informationSources")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("informationSources")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QDirectedRelationship::source");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingMessages")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingMessages")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingMessages")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Determines which Messages will realize the specified flow.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingMessages")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingMessages")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingActivityEdges")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingActivityEdges")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingActivityEdges")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Determines which ActivityEdges will realize the specified flow.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingActivityEdges")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizingActivityEdges")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizations")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizations")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizations")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Determines which Relationship will realize the specified flow");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizations")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QInformationFlow")][QString::fromLatin1("realizations")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");

    QWrappedObject::setPropertyData();
}

#include "moc_qinformationflow.cpp"

QT_END_NAMESPACE_QTUML

