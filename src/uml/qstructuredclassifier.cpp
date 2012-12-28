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

#include "qstructuredclassifier.h"
#include "qstructuredclassifier_p.h"

#include <QtUml/QProperty>
#include <QtUml/QConnector>
#include <QtUml/QConnectableElement>

QT_BEGIN_NAMESPACE_QTUML

QStructuredClassifierPrivate::QStructuredClassifierPrivate()
{
}

QStructuredClassifierPrivate::~QStructuredClassifierPrivate()
{
}

void QStructuredClassifierPrivate::addRole(QConnectableElement *role)
{
    // This is a read-only derived-union association end

    if (!this->roles.contains(role)) {
        this->roles.insert(role);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QNamespacePrivate *>(this))->addMember(qwrappedobject_cast<QNamedElement *>(role));
    }
}

void QStructuredClassifierPrivate::removeRole(QConnectableElement *role)
{
    // This is a read-only derived-union association end

    if (this->roles.contains(role)) {
        this->roles.remove(role);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QNamespacePrivate *>(this))->removeMember(qwrappedobject_cast<QNamedElement *>(role));
    }
}

/*!
    \class QStructuredClassifier

    \inmodule QtUml

    \brief A structured classifier is an abstract metaclass that represents any classifier whose behavior can be fully or partly described by the collaboration of owned or referenced instances.
 */

QStructuredClassifier::QStructuredClassifier(QWrappedObject *parent, QWrappedObject *wrapper) :
    QClassifier(*new QStructuredClassifierPrivate, parent, wrapper)
{
}

QStructuredClassifier::QStructuredClassifier(QStructuredClassifierPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QClassifier(dd, parent, wrapper)
{
}

QStructuredClassifier::~QStructuredClassifier()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QStructuredClassifier
// ---------------------------------------------------------------

/*!
    References the roles that instances may play in this classifier.
 */
const QSet<QConnectableElement *> &QStructuredClassifier::roles() const
{
    // This is a read-only derived-union association end

    Q_D(const QStructuredClassifier);
    return d->roles;
}

/*!
    References the properties owned by the classifier.
 */
const QList<QProperty *> &QStructuredClassifier::ownedAttributes() const
{
    // This is a read-write association end

    Q_D(const QStructuredClassifier);
    return d->ownedAttributes;
}

void QStructuredClassifier::addOwnedAttribute(QProperty *ownedAttribute)
{
    // This is a read-write association end

    Q_D(QStructuredClassifier);
    if (!d->ownedAttributes.contains(ownedAttribute)) {
        d->ownedAttributes.append(ownedAttribute);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QClassifierPrivate *>(d))->addAttribute(qwrappedobject_cast<QProperty *>(ownedAttribute));
        (qwrappedobject_cast<QNamespacePrivate *>(d))->addOwnedMember(qwrappedobject_cast<QNamedElement *>(ownedAttribute));
        (qwrappedobject_cast<QStructuredClassifierPrivate *>(d))->addRole(qwrappedobject_cast<QConnectableElement *>(ownedAttribute));
    }
}

void QStructuredClassifier::removeOwnedAttribute(QProperty *ownedAttribute)
{
    // This is a read-write association end

    Q_D(QStructuredClassifier);
    if (d->ownedAttributes.contains(ownedAttribute)) {
        d->ownedAttributes.removeAll(ownedAttribute);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QClassifierPrivate *>(d))->removeAttribute(qwrappedobject_cast<QProperty *>(ownedAttribute));
        (qwrappedobject_cast<QNamespacePrivate *>(d))->removeOwnedMember(qwrappedobject_cast<QNamedElement *>(ownedAttribute));
        (qwrappedobject_cast<QStructuredClassifierPrivate *>(d))->removeRole(qwrappedobject_cast<QConnectableElement *>(ownedAttribute));
    }
}

/*!
    References the properties specifying instances that the classifier owns by composition. This association is derived, selecting those owned properties where isComposite is true.
 */
const QSet<QProperty *> &QStructuredClassifier::parts() const
{
    // This is a read-only derived association end

    qWarning("QStructuredClassifier::parts: to be implemented (this is a derived associationend)");

    return *(new QSet<QProperty *>); // change here to your derived return
}

/*!
    References the connectors owned by the classifier.
 */
const QSet<QConnector *> &QStructuredClassifier::ownedConnectors() const
{
    // This is a read-write association end

    Q_D(const QStructuredClassifier);
    return d->ownedConnectors;
}

void QStructuredClassifier::addOwnedConnector(QConnector *ownedConnector)
{
    // This is a read-write association end

    Q_D(QStructuredClassifier);
    if (!d->ownedConnectors.contains(ownedConnector)) {
        d->ownedConnectors.insert(ownedConnector);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QClassifierPrivate *>(d))->addFeature(qwrappedobject_cast<QFeature *>(ownedConnector));
        (qwrappedobject_cast<QNamespacePrivate *>(d))->addOwnedMember(qwrappedobject_cast<QNamedElement *>(ownedConnector));
    }
}

void QStructuredClassifier::removeOwnedConnector(QConnector *ownedConnector)
{
    // This is a read-write association end

    Q_D(QStructuredClassifier);
    if (d->ownedConnectors.contains(ownedConnector)) {
        d->ownedConnectors.remove(ownedConnector);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QClassifierPrivate *>(d))->removeFeature(qwrappedobject_cast<QFeature *>(ownedConnector));
        (qwrappedobject_cast<QNamespacePrivate *>(d))->removeOwnedMember(qwrappedobject_cast<QNamedElement *>(ownedConnector));
    }
}

#include "moc_qstructuredclassifier.cpp"

QT_END_NAMESPACE_QTUML

