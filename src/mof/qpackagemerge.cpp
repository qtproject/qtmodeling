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

#include "qpackagemerge.h"
#include "qpackagemerge_p.h"

#include <QtMof/QPackage>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

namespace QtMof
{

QPackageMergePrivate::QPackageMergePrivate() :
    mergedPackage(0),
    receivingPackage(0)
{
}

QPackageMergePrivate::~QPackageMergePrivate()
{
}

/*!
    \class QPackageMerge

    \inmodule QtMof

    \brief A package merge defines how the contents of one package are extended by the contents of another package.
 */

QPackageMerge::QPackageMerge(QWrappedObject *wrapper, QWrappedObject *parent) :
    QDirectedRelationship(*new QPackageMergePrivate, wrapper, parent)
{
    setPropertyData();
}

QPackageMerge::QPackageMerge(QPackageMergePrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QDirectedRelationship(dd, wrapper, parent)
{
    setPropertyData();
}

QPackageMerge::~QPackageMerge()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QPackageMerge
// ---------------------------------------------------------------

/*!
    References the Package that is to be merged with the receiving package of the PackageMerge.
 */
QPackage *QPackageMerge::mergedPackage() const
{
    // This is a read-write association end

    Q_D(const QPackageMerge);
    return d->mergedPackage;
}

void QPackageMerge::setMergedPackage(QPackage *mergedPackage)
{
    // This is a read-write association end

    Q_D(QPackageMerge);
    if (d->mergedPackage != mergedPackage) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QDirectedRelationshipPrivate *>(d))->removeTarget(qwrappedobject_cast<QElement *>(d->mergedPackage));

        d->mergedPackage = mergedPackage;

        // Adjust subsetted property(ies)
        if (mergedPackage) {
            (qwrappedobject_cast<QDirectedRelationshipPrivate *>(d))->addTarget(qwrappedobject_cast<QElement *>(mergedPackage));
        }
    }
}

/*!
    References the Package that is being extended with the contents of the merged package of the PackageMerge.
 */
QPackage *QPackageMerge::receivingPackage() const
{
    // This is a read-write association end

    Q_D(const QPackageMerge);
    return d->receivingPackage;
}

void QPackageMerge::setReceivingPackage(QPackage *receivingPackage)
{
    // This is a read-write association end

    Q_D(QPackageMerge);
    if (d->receivingPackage != receivingPackage) {
        // Adjust opposite property
        if (d->receivingPackage)
            d->receivingPackage->removePackageMerge(this);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QDirectedRelationshipPrivate *>(d))->removeSource(qwrappedobject_cast<QElement *>(d->receivingPackage));

        d->receivingPackage = receivingPackage;

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->setOwner(qwrappedobject_cast<QElement *>(receivingPackage));
        if (receivingPackage) {
            (qwrappedobject_cast<QDirectedRelationshipPrivate *>(d))->addSource(qwrappedobject_cast<QElement *>(receivingPackage));
        }

        // Adjust opposite property
        if (receivingPackage)
            receivingPackage->addPackageMerge(this);
    }
}

void QPackageMerge::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtMof::QPackageMerge")][QString::fromLatin1("mergedPackage")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtMof::QPackageMerge")][QString::fromLatin1("mergedPackage")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtMof::QPackageMerge")][QString::fromLatin1("mergedPackage")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("References the Package that is to be merged with the receiving package of the PackageMerge.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtMof::QPackageMerge")][QString::fromLatin1("mergedPackage")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtMof::QPackageMerge")][QString::fromLatin1("mergedPackage")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QDirectedRelationship::targets");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtMof::QPackageMerge")][QString::fromLatin1("mergedPackage")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtMof::QPackageMerge")][QString::fromLatin1("receivingPackage")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtMof::QPackageMerge")][QString::fromLatin1("receivingPackage")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtMof::QPackageMerge")][QString::fromLatin1("receivingPackage")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("References the Package that is being extended with the contents of the merged package of the PackageMerge.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtMof::QPackageMerge")][QString::fromLatin1("receivingPackage")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtMof::QPackageMerge")][QString::fromLatin1("receivingPackage")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QElement::owner QDirectedRelationship::sources");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtMof::QPackageMerge")][QString::fromLatin1("receivingPackage")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QPackage::packageMerge");

    QDirectedRelationship::setPropertyData();
}

}

QT_END_NAMESPACE

#include "moc_qpackagemerge.cpp"

