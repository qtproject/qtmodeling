/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtMof module of the Qt Toolkit.
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

#include "qclass.h"
#include "qclass_p.h"

#include <QtMof/QNamedElement>
#include <QtMof/QProperty>
#include <QtMof/QOperation>

QT_BEGIN_NAMESPACE_QTMOF

QClassPrivate::QClassPrivate() :
    isAbstract(false),
    nestedClassifiers(new QList<QClassifier *>),
    ownedOperations(new QList<QOperation *>),
    ownedAttributes(new QList<QProperty *>)
{
}

QClassPrivate::~QClassPrivate()
{
    delete nestedClassifiers;
    delete ownedOperations;
    delete ownedAttributes;
}

/*!
    \class QClass

    \inmodule QtMof

    \brief A class describes a set of objects that share the same specifications of features, constraints, and semantics.
 */

QClass::QClass(QMofObject *parent, QMofObject *wrapper) :
    QClassifier(*new QClassPrivate, parent, wrapper)
{
}

QClass::QClass(QClassPrivate &dd, QMofObject *parent, QMofObject *wrapper) :
    QClassifier(dd, parent, wrapper)
{
}

QClass::~QClass()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QClass
// ---------------------------------------------------------------

/*!
    If true, the Classifier does not provide a complete declaration and can typically not be instantiated. An abstract classifier is intended to be used by other classifiers e.g. as the target of general metarelationships or generalization relationships.
 */
bool QClass::isAbstract() const
{
    // This is a read-write attribute

    Q_D(const QClass);
    return d->isAbstract;
}

void QClass::setAbstract(bool isAbstract)
{
    // This is a read-write attribute

    Q_D(QClass);
    if (d->isAbstract != isAbstract) {
        d->isAbstract = isAbstract;
    }
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QClass
// ---------------------------------------------------------------

/*!
    References all the Classifiers that are defined (nested) within the Class.
 */
const QList<QClassifier *> *QClass::nestedClassifiers() const
{
    // This is a read-write association end

    Q_D(const QClass);
    return d->nestedClassifiers;
}

void QClass::addNestedClassifier(QClassifier *nestedClassifier)
{
    // This is a read-write association end

    Q_D(QClass);
    if (!d->nestedClassifiers->contains(nestedClassifier)) {
        d->nestedClassifiers->append(nestedClassifier);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QNamespacePrivate *>(d))->addOwnedMember(qmofobject_cast<QNamedElement *>(nestedClassifier));
    }
}

void QClass::removeNestedClassifier(QClassifier *nestedClassifier)
{
    // This is a read-write association end

    Q_D(QClass);
    if (d->nestedClassifiers->contains(nestedClassifier)) {
        d->nestedClassifiers->removeAll(nestedClassifier);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QNamespacePrivate *>(d))->removeOwnedMember(qmofobject_cast<QNamedElement *>(nestedClassifier));
    }
}

/*!
    The operations owned by the class.
 */
const QList<QOperation *> *QClass::ownedOperations() const
{
    // This is a read-write association end

    Q_D(const QClass);
    return d->ownedOperations;
}

void QClass::addOwnedOperation(QOperation *ownedOperation)
{
    // This is a read-write association end

    Q_D(QClass);
    if (!d->ownedOperations->contains(ownedOperation)) {
        d->ownedOperations->append(ownedOperation);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QClassifierPrivate *>(d))->addFeature(qmofobject_cast<QFeature *>(ownedOperation));
        (qmofobject_cast<QNamespacePrivate *>(d))->addOwnedMember(qmofobject_cast<QNamedElement *>(ownedOperation));

        // Adjust opposite property
        ownedOperation->setClass_(this);
    }
}

void QClass::removeOwnedOperation(QOperation *ownedOperation)
{
    // This is a read-write association end

    Q_D(QClass);
    if (d->ownedOperations->contains(ownedOperation)) {
        d->ownedOperations->removeAll(ownedOperation);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QClassifierPrivate *>(d))->removeFeature(qmofobject_cast<QFeature *>(ownedOperation));
        (qmofobject_cast<QNamespacePrivate *>(d))->removeOwnedMember(qmofobject_cast<QNamedElement *>(ownedOperation));

        // Adjust opposite property
        ownedOperation->setClass_(0);
    }
}

/*!
    The attributes (i.e. the properties) owned by the class.
 */
const QList<QProperty *> *QClass::ownedAttributes() const
{
    // This is a read-write association end

    Q_D(const QClass);
    return d->ownedAttributes;
}

void QClass::addOwnedAttribute(QProperty *ownedAttribute)
{
    // This is a read-write association end

    Q_D(QClass);
    if (!d->ownedAttributes->contains(ownedAttribute)) {
        d->ownedAttributes->append(ownedAttribute);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QClassifierPrivate *>(d))->addAttribute(qmofobject_cast<QProperty *>(ownedAttribute));
        (qmofobject_cast<QNamespacePrivate *>(d))->addOwnedMember(qmofobject_cast<QNamedElement *>(ownedAttribute));

        // Adjust opposite property
        ownedAttribute->setClass_(this);
    }
}

void QClass::removeOwnedAttribute(QProperty *ownedAttribute)
{
    // This is a read-write association end

    Q_D(QClass);
    if (d->ownedAttributes->contains(ownedAttribute)) {
        d->ownedAttributes->removeAll(ownedAttribute);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QClassifierPrivate *>(d))->removeAttribute(qmofobject_cast<QProperty *>(ownedAttribute));
        (qmofobject_cast<QNamespacePrivate *>(d))->removeOwnedMember(qmofobject_cast<QNamedElement *>(ownedAttribute));

        // Adjust opposite property
        ownedAttribute->setClass_(0);
    }
}

/*!
    This gives the superclasses of a class.
 */
const QSet<QClass *> *QClass::superClasses() const
{
    // This is a read-write derived association end

    qWarning("QClass::superClasses: to be implemented (this is a derived associationend)");

    return 0; // change here to your derived return
}

void QClass::addSuperClass(QClass *superClass)
{
    // This is a read-write derived association end

    qWarning("QClass::addSuperClass: to be implemented (this is a derived associationend)");
    Q_UNUSED(superClass);

    if (false) { // change to your derived inclusion criteria
        // change to your derived code
    }
}

void QClass::removeSuperClass(QClass *superClass)
{
    // This is a read-write derived association end

    qWarning("QClass::removeSuperClass: to be implemented (this is a derived associationend)");
    Q_UNUSED(superClass);

    if (false) { // change to your derived exclusion criteria
        // change to your derived code
    }
}

/*!
    The inherit operation is overridden to exclude redefined properties.
 */
const QSet<QNamedElement *> *QClass::inherit(const QSet<QNamedElement *> *inhs) const
{
    qWarning("QClass::inherit: operation to be implemented");
    Q_UNUSED(inhs);

    return 0; // change here to your derived return
}

#include "moc_qclass.cpp"

QT_END_NAMESPACE_QTMOF
