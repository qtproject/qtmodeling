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

#include "qtype.h"
#include "qtype_p.h"

#include <QtMof/QPackage>
#include <QtMof/QMofObject>

QT_BEGIN_NAMESPACE_QTMOF

QTypePrivate::QTypePrivate() :
    package(0)
{
}

QTypePrivate::~QTypePrivate()
{
}

/*!
    \class QType

    \inmodule QtMof

    \brief A type constrains the values represented by a typed element.
 */

QType::QType(QWrappedObject *parent, QWrappedObject *wrapper) :
    QPackageableElement(*new QTypePrivate, parent, wrapper)
{
}

QType::QType(QTypePrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QPackageableElement(dd, parent, wrapper)
{
}

QType::~QType()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QType
// ---------------------------------------------------------------

/*!
    Specifies the owning package of this classifier, if any.
 */
QPackage *QType::package() const
{
    // This is a read-write association end

    Q_D(const QType);
    return d->package;
}

void QType::setPackage(QPackage *package)
{
    // This is a read-write association end

    Q_D(QType);
    if (d->package != package) {
        // Adjust opposite property
        if (d->package)
            d->package->removeOwnedType(this);

        d->package = package;

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QNamedElementPrivate *>(d))->setNamespace_(qwrappedobject_cast<QNamespace *>(package));

        // Adjust opposite property
        if (package)
            package->addOwnedType(this);
    }
}

/*!
    The query conformsTo() gives true for a type that conforms to another. By default, two types do not conform to each other. This query is intended to be redefined for specific conformance situations.
 */
bool QType::conformsTo(const QType *other) const
{
    qWarning("QType::conformsTo: operation to be implemented");
    Q_UNUSED(other);

    return bool(); // change here to your derived return
}

bool QType::isInstance(const QMofObject *object) const
{
    qWarning("QType::isInstance: operation to be implemented");
    Q_UNUSED(object);

    return bool(); // change here to your derived return
}

void QType::registerMetaTypes() const
{
    qRegisterMetaType<QPackage *>("QPackage *");
    qRegisterMetaType<QSet<QPackage *>>("QSet<QPackage *>");
    qRegisterMetaType<QList<QPackage *>>("QList<QPackage *>");

    qRegisterMetaType<QMofObject *>("QMofObject *");
    qRegisterMetaType<QSet<QMofObject *>>("QSet<QMofObject *>");
    qRegisterMetaType<QList<QMofObject *>>("QList<QMofObject *>");

    QPackageableElement::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qtype.cpp"

QT_END_NAMESPACE_QTMOF
