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

#include "qdatatype.h"
#include "qdatatype_p.h"

#include <QtMof/QProperty>
#include <QtMof/QOperation>
#include <QtMof/QNamedElement>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE_QTMOF

QDataTypePrivate::QDataTypePrivate()
{
}

QDataTypePrivate::~QDataTypePrivate()
{
}

/*!
    \class QDataType

    \inmodule QtMof

    \brief A data type is a type whose instances are identified only by their value. A data type may contain attributes to support the modeling of structured data types.
 */

QDataType::QDataType(QWrappedObject *wrapper, QWrappedObject *parent) :
    QClassifier(*new QDataTypePrivate, wrapper, parent)
{
    setPropertyData();
}

QDataType::QDataType(QDataTypePrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QClassifier(dd, wrapper, parent)
{
    setPropertyData();
}

QDataType::~QDataType()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QDataType
// ---------------------------------------------------------------

/*!
    The Operations owned by the DataType.
 */
QList<QOperation *> QDataType::ownedOperations() const
{
    // This is a read-write association end

    Q_D(const QDataType);
    return d->ownedOperations;
}

void QDataType::addOwnedOperation(QOperation *ownedOperation)
{
    // This is a read-write association end

    Q_D(QDataType);
    if (!d->ownedOperations.contains(ownedOperation)) {
        d->ownedOperations.append(ownedOperation);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QClassifierPrivate *>(d))->addFeature(qwrappedobject_cast<QFeature *>(ownedOperation));
        (qwrappedobject_cast<QNamespacePrivate *>(d))->addOwnedMember(qwrappedobject_cast<QNamedElement *>(ownedOperation));

        // Adjust opposite property
        ownedOperation->setDatatype(this);
    }
}

void QDataType::removeOwnedOperation(QOperation *ownedOperation)
{
    // This is a read-write association end

    Q_D(QDataType);
    if (d->ownedOperations.contains(ownedOperation)) {
        d->ownedOperations.removeAll(ownedOperation);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QClassifierPrivate *>(d))->removeFeature(qwrappedobject_cast<QFeature *>(ownedOperation));
        (qwrappedobject_cast<QNamespacePrivate *>(d))->removeOwnedMember(qwrappedobject_cast<QNamedElement *>(ownedOperation));

        // Adjust opposite property
        ownedOperation->setDatatype(0);
    }
}

/*!
    The Attributes owned by the DataType.
 */
QList<QProperty *> QDataType::ownedAttributes() const
{
    // This is a read-write association end

    Q_D(const QDataType);
    return d->ownedAttributes;
}

void QDataType::addOwnedAttribute(QProperty *ownedAttribute)
{
    // This is a read-write association end

    Q_D(QDataType);
    if (!d->ownedAttributes.contains(ownedAttribute)) {
        d->ownedAttributes.append(ownedAttribute);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QClassifierPrivate *>(d))->addAttribute(qwrappedobject_cast<QProperty *>(ownedAttribute));
        (qwrappedobject_cast<QNamespacePrivate *>(d))->addOwnedMember(qwrappedobject_cast<QNamedElement *>(ownedAttribute));

        // Adjust opposite property
        ownedAttribute->setDatatype(this);
    }
}

void QDataType::removeOwnedAttribute(QProperty *ownedAttribute)
{
    // This is a read-write association end

    Q_D(QDataType);
    if (d->ownedAttributes.contains(ownedAttribute)) {
        d->ownedAttributes.removeAll(ownedAttribute);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QClassifierPrivate *>(d))->removeAttribute(qwrappedobject_cast<QProperty *>(ownedAttribute));
        (qwrappedobject_cast<QNamespacePrivate *>(d))->removeOwnedMember(qwrappedobject_cast<QNamedElement *>(ownedAttribute));

        // Adjust opposite property
        ownedAttribute->setDatatype(0);
    }
}

/*!
    The inherit operation is overridden to exclude redefined properties.
 */
QSet<QNamedElement *> QDataType::inherit(QSet<QNamedElement *> inhs) const
{
    qWarning("QDataType::inherit: operation to be implemented");
    Q_UNUSED(inhs);

    return QSet<QNamedElement *>(); // change here to your derived return
}

void QDataType::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QDataType")][QString::fromLatin1("ownedOperations")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QDataType")][QString::fromLatin1("ownedOperations")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QDataType")][QString::fromLatin1("ownedOperations")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The Operations owned by the DataType.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QDataType")][QString::fromLatin1("ownedOperations")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QDataType")][QString::fromLatin1("ownedOperations")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QClassifier::features QNamespace::ownedMembers");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QDataType")][QString::fromLatin1("ownedOperations")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QOperation::datatype");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QDataType")][QString::fromLatin1("ownedAttributes")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QDataType")][QString::fromLatin1("ownedAttributes")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QDataType")][QString::fromLatin1("ownedAttributes")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The Attributes owned by the DataType.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QDataType")][QString::fromLatin1("ownedAttributes")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QDataType")][QString::fromLatin1("ownedAttributes")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QClassifier::attributes QNamespace::ownedMembers");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QDataType")][QString::fromLatin1("ownedAttributes")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QProperty::datatype");

    QClassifier::setPropertyData();
}

#include "moc_qdatatype.cpp"

QT_END_NAMESPACE_QTMOF
