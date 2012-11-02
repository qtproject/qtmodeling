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

QInstanceSpecification::QInstanceSpecification(QObject *parent) :
    QObject(*new QInstanceSpecificationPrivate, parent),
    _wrappedDeployedArtifact(new QDeployedArtifact(this)),
    _wrappedPackageableElement(new QPackageableElement(this)),
    _wrappedDeploymentTarget(new QDeploymentTarget(this))
{
}

QInstanceSpecification::QInstanceSpecification(QInstanceSpecificationPrivate &dd, QObject *parent) :
    QObject(dd, parent),
    _wrappedDeployedArtifact(new QDeployedArtifact(this)),
    _wrappedPackageableElement(new QPackageableElement(this)),
    _wrappedDeploymentTarget(new QDeploymentTarget(this))
{
}

QInstanceSpecification::~QInstanceSpecification()
{
}

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
        d->QElementPrivate::removeOwnedElement(dynamic_cast<QElement *>(d->specification));

        d->specification = specification;

        // Adjust subsetted property(ies)
        if (specification) {
            d->QElementPrivate::addOwnedElement(dynamic_cast<QElement *>(specification));
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
        d->QElementPrivate::addOwnedElement(dynamic_cast<QElement *>(slot_));

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

        // Adjust subsetted property(ies)
        d->QElementPrivate::removeOwnedElement(dynamic_cast<QElement *>(slot_));

        // Adjust opposite property
        slot_->setOwningInstance(0);
    }
}

#include "moc_qinstancespecification.cpp"

QT_END_NAMESPACE_QTUML

