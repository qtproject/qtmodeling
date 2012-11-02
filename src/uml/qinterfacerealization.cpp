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

#include "qinterfacerealization.h"
#include "qinterfacerealization_p.h"

#include <QtUml/QInterface>
#include <QtUml/QBehavioredClassifier>

QT_BEGIN_NAMESPACE_QTUML

QInterfaceRealizationPrivate::QInterfaceRealizationPrivate() :
    implementingClassifier(0),
    contract(0)
{
}

QInterfaceRealizationPrivate::~QInterfaceRealizationPrivate()
{
}

/*!
    \class QInterfaceRealization

    \inmodule QtUml

    \brief An interface realization is a specialized realization relationship between a classifier and an interface. This relationship signifies that the realizing classifier conforms to the contract specified by the interface.
 */

QInterfaceRealization::QInterfaceRealization(QObject *parent) :
    QRealization(*new QInterfaceRealizationPrivate, parent)
{
}

QInterfaceRealization::QInterfaceRealization(QInterfaceRealizationPrivate &dd, QObject *parent) :
    QRealization(dd, parent)
{
}

QInterfaceRealization::~QInterfaceRealization()
{
}

/*!
    References the BehavioredClassifier that owns this Interfacerealization (i.e., the classifier that realizes the Interface to which it points).
 */
QBehavioredClassifier *QInterfaceRealization::implementingClassifier() const
{
    // This is a read-write association end

    Q_D(const QInterfaceRealization);
    return d->implementingClassifier;
}

void QInterfaceRealization::setImplementingClassifier(QBehavioredClassifier *implementingClassifier)
{
    // This is a read-write association end

    Q_D(QInterfaceRealization);
    if (d->implementingClassifier != implementingClassifier) {
        // Adjust opposite property
        if (d->implementingClassifier)
            d->implementingClassifier->removeInterfaceRealization(this);

        // Adjust subsetted property(ies)
        QDependency::removeClient(dynamic_cast<QNamedElement *>(d->implementingClassifier));

        d->implementingClassifier = implementingClassifier;

        // Adjust subsetted property(ies)
        d->QElementPrivate::setOwner(dynamic_cast<QElement *>(implementingClassifier));
        if (implementingClassifier) {
            QDependency::addClient(dynamic_cast<QNamedElement *>(implementingClassifier));
        }

        // Adjust opposite property
        if (implementingClassifier)
            implementingClassifier->addInterfaceRealization(this);
    }
}

/*!
    References the Interface specifying the conformance contract.
 */
QInterface *QInterfaceRealization::contract() const
{
    // This is a read-write association end

    Q_D(const QInterfaceRealization);
    return d->contract;
}

void QInterfaceRealization::setContract(QInterface *contract)
{
    // This is a read-write association end

    Q_D(QInterfaceRealization);
    if (d->contract != contract) {
        // Adjust subsetted property(ies)
        QDependency::removeSupplier(dynamic_cast<QNamedElement *>(d->contract));

        d->contract = contract;

        // Adjust subsetted property(ies)
        if (contract) {
            QDependency::addSupplier(dynamic_cast<QNamedElement *>(contract));
        }
    }
}

// Overriden methods for subsetted properties

void QInterfaceRealization::addClient(QBehavioredClassifier *implementingClassifier)
{
    setImplementingClassifier(implementingClassifier);
}

void QInterfaceRealization::removeClient(QBehavioredClassifier *implementingClassifier)
{
    setImplementingClassifier(0);
}

void QInterfaceRealization::addSupplier(QInterface *contract)
{
    setContract(contract);
}

void QInterfaceRealization::removeSupplier(QInterface *contract)
{
    setContract(0);
}

#include "moc_qinterfacerealization.cpp"

QT_END_NAMESPACE_QTUML

