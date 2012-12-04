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

#include "qinstancespecification.h"
#include "qinstancespecification_p.h"

#include <QtUml/QClassifier>
#include <QtUml/QSlot>
#include <QtUml/QValueSpecification>

QT_BEGIN_NAMESPACE_QTUML

QInstanceSpecificationPrivate::QInstanceSpecificationPrivate() :
    classifiers(new QSet<QClassifier *>),
    specification(0),
    slots_(new QSet<QSlot *>)
{
}

QInstanceSpecificationPrivate::~QInstanceSpecificationPrivate()
{
    delete classifiers;
    delete slots_;
}

/*!
    \class QInstanceSpecification

    \inmodule QtUml

    \brief An instance specification has the capability of being a deployment target in a deployment relationship, in the case that it is an instance of a node. It is also has the capability of being a deployed artifact, if it is an instance of an artifact.An instance specification is a model element that represents an instance in a modeled system.
 */

QInstanceSpecification::QInstanceSpecification(QUmlObject *parent, QUmlObject *wrapper) :
    QUmlObject(*new QInstanceSpecificationPrivate, parent, wrapper),
    _wrappedDeployedArtifact(new QDeployedArtifact(this, this)),
    _wrappedPackageableElement(new QPackageableElement(this, this)),
    _wrappedDeploymentTarget(new QDeploymentTarget(this, this))
{
}

QInstanceSpecification::QInstanceSpecification(QInstanceSpecificationPrivate &dd, QUmlObject *parent, QUmlObject *wrapper) :
    QUmlObject(dd, parent, wrapper),
    _wrappedDeployedArtifact(new QDeployedArtifact(this, this)),
    _wrappedPackageableElement(new QPackageableElement(this, this)),
    _wrappedDeploymentTarget(new QDeploymentTarget(this, this))
{
}

QInstanceSpecification::~QInstanceSpecification()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QElement
// ---------------------------------------------------------------

/*!
    The Elements owned by this element.
 */
const QSet<QElement *> *QInstanceSpecification::ownedElements() const
{
    return (qumlobject_cast<const QElement *>(this))->ownedElements();
}

/*!
    The Element that owns this element.
 */
QElement *QInstanceSpecification::owner() const
{
    return (qumlobject_cast<const QElement *>(this))->owner();
}

/*!
    The Comments owned by this element.
 */
const QSet<QComment *> *QInstanceSpecification::ownedComments() const
{
    return (qumlobject_cast<const QElement *>(this))->ownedComments();
}

void QInstanceSpecification::addOwnedComment(QComment *ownedComment)
{
    (qumlobject_cast<QElement *>(this))->addOwnedComment(ownedComment);
}

void QInstanceSpecification::removeOwnedComment(QComment *ownedComment)
{
    (qumlobject_cast<QElement *>(this))->removeOwnedComment(ownedComment);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The name of the NamedElement.
 */
QString QInstanceSpecification::name() const
{
    return (qumlobject_cast<const QNamedElement *>(this))->name();
}

void QInstanceSpecification::setName(QString name)
{
    (qumlobject_cast<QNamedElement *>(this))->setName(name);
}

/*!
    A name which allows the NamedElement to be identified within a hierarchy of nested Namespaces. It is constructed from the names of the containing namespaces starting at the root of the hierarchy and ending with the name of the NamedElement itself.
 */
QString QInstanceSpecification::qualifiedName() const
{
    return (qumlobject_cast<const QNamedElement *>(this))->qualifiedName();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The string expression used to define the name of this named element.
 */
QStringExpression *QInstanceSpecification::nameExpression() const
{
    return (qumlobject_cast<const QNamedElement *>(this))->nameExpression();
}

void QInstanceSpecification::setNameExpression(QStringExpression *nameExpression)
{
    (qumlobject_cast<QNamedElement *>(this))->setNameExpression(nameExpression);
}

/*!
    Specifies the namespace that owns the NamedElement.
 */
QNamespace *QInstanceSpecification::namespace_() const
{
    return (qumlobject_cast<const QNamedElement *>(this))->namespace_();
}

/*!
    Indicates the dependencies that reference the client.
 */
const QSet<QDependency *> *QInstanceSpecification::clientDependencies() const
{
    return (qumlobject_cast<const QNamedElement *>(this))->clientDependencies();
}

void QInstanceSpecification::addClientDependency(QDependency *clientDependency)
{
    (qumlobject_cast<QNamedElement *>(this))->addClientDependency(clientDependency);
}

void QInstanceSpecification::removeClientDependency(QDependency *clientDependency)
{
    (qumlobject_cast<QNamedElement *>(this))->removeClientDependency(clientDependency);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QParameterableElement
// ---------------------------------------------------------------

/*!
    The formal template parameter that owns this element.
 */
QTemplateParameter *QInstanceSpecification::owningTemplateParameter() const
{
    return (qumlobject_cast<const QParameterableElement *>(this))->owningTemplateParameter();
}

void QInstanceSpecification::setOwningTemplateParameter(QTemplateParameter *owningTemplateParameter)
{
    (qumlobject_cast<QParameterableElement *>(this))->setOwningTemplateParameter(owningTemplateParameter);
}

/*!
    The template parameter that exposes this element as a formal parameter.
 */
QTemplateParameter *QInstanceSpecification::templateParameter() const
{
    return (qumlobject_cast<const QParameterableElement *>(this))->templateParameter();
}

void QInstanceSpecification::setTemplateParameter(QTemplateParameter *templateParameter)
{
    (qumlobject_cast<QParameterableElement *>(this))->setTemplateParameter(templateParameter);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QPackageableElement
// ---------------------------------------------------------------

/*!
    Indicates that packageable elements must always have a visibility, i.e., visibility is not optional.
 */
QtUml::VisibilityKind QInstanceSpecification::visibility() const
{
    return (qumlobject_cast<const QPackageableElement *>(this))->visibility();
}

void QInstanceSpecification::setVisibility(QtUml::VisibilityKind visibility)
{
    (qumlobject_cast<QPackageableElement *>(this))->setVisibility(visibility);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QDeploymentTarget
// ---------------------------------------------------------------

/*!
    The set of elements that are manifested in an Artifact that is involved in Deployment to a DeploymentTarget.
 */
const QSet<QPackageableElement *> *QInstanceSpecification::deployedElements() const
{
    return (qumlobject_cast<const QDeploymentTarget *>(this))->deployedElements();
}

/*!
    The set of Deployments for a DeploymentTarget.
 */
const QSet<QDeployment *> *QInstanceSpecification::deployments() const
{
    return (qumlobject_cast<const QDeploymentTarget *>(this))->deployments();
}

void QInstanceSpecification::addDeployment(QDeployment *deployment)
{
    (qumlobject_cast<QDeploymentTarget *>(this))->addDeployment(deployment);
}

void QInstanceSpecification::removeDeployment(QDeployment *deployment)
{
    (qumlobject_cast<QDeploymentTarget *>(this))->removeDeployment(deployment);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QInstanceSpecification
// ---------------------------------------------------------------

/*!
    The classifier or classifiers of the represented instance. If multiple classifiers are specified, the instance is classified by all of them.
 */
const QSet<QClassifier *> *QInstanceSpecification::classifiers() const
{
    // This is a read-write association end

    Q_D(const QInstanceSpecification);
    return d->classifiers;
}

void QInstanceSpecification::addClassifier(QClassifier *classifier)
{
    // This is a read-write association end

    Q_D(QInstanceSpecification);
    if (!d->classifiers->contains(classifier)) {
        d->classifiers->insert(classifier);
    }
}

void QInstanceSpecification::removeClassifier(QClassifier *classifier)
{
    // This is a read-write association end

    Q_D(QInstanceSpecification);
    if (d->classifiers->contains(classifier)) {
        d->classifiers->remove(classifier);
    }
}

/*!
    A specification of how to compute, derive, or construct the instance.
 */
QValueSpecification *QInstanceSpecification::specification() const
{
    // This is a read-write association end

    Q_D(const QInstanceSpecification);
    return d->specification;
}

void QInstanceSpecification::setSpecification(QValueSpecification *specification)
{
    // This is a read-write association end

    Q_D(QInstanceSpecification);
    if (d->specification != specification) {
        // Adjust subsetted property(ies)
        (qumlobject_cast<QElementPrivate *>(d))->removeOwnedElement(qumlobject_cast<QElement *>(d->specification));

        d->specification = specification;

        // Adjust subsetted property(ies)
        if (specification) {
            (qumlobject_cast<QElementPrivate *>(d))->addOwnedElement(qumlobject_cast<QElement *>(specification));
        }
    }
}

/*!
    A slot giving the value or values of a structural feature of the instance. An instance specification can have one slot per structural feature of its classifiers, including inherited features. It is not necessary to model a slot for each structural feature, in which case the instance specification is a partial description.
 */
const QSet<QSlot *> *QInstanceSpecification::slots_() const
{
    // This is a read-write association end

    Q_D(const QInstanceSpecification);
    return d->slots_;
}

void QInstanceSpecification::addSlot_(QSlot *slot_)
{
    // This is a read-write association end

    Q_D(QInstanceSpecification);
    if (!d->slots_->contains(slot_)) {
        d->slots_->insert(slot_);

        // Adjust subsetted property(ies)
        (qumlobject_cast<QElementPrivate *>(d))->addOwnedElement(qumlobject_cast<QElement *>(slot_));

        // Adjust opposite property
        slot_->setOwningInstance(this);
    }
}

void QInstanceSpecification::removeSlot_(QSlot *slot_)
{
    // This is a read-write association end

    Q_D(QInstanceSpecification);
    if (d->slots_->contains(slot_)) {
        d->slots_->remove(slot_);
        slot_->setParent(0);

        // Adjust subsetted property(ies)
        (qumlobject_cast<QElementPrivate *>(d))->removeOwnedElement(qumlobject_cast<QElement *>(slot_));

        // Adjust opposite property
        slot_->setOwningInstance(0);
    }
}

#include "moc_qinstancespecification.cpp"

QT_END_NAMESPACE_QTUML

