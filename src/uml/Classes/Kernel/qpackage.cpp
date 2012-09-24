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

#include "qpackage.h"
//#include "qpackage_p.h"

QT_BEGIN_NAMESPACE_UML_CLASSES_KERNEL

/*!
    \class QPackage

    \inmodule QtUml

    \brief A package is used to group elements, and provides a namespace for the grouped elements.
 */

QPackage::QPackage()
{
}

QPackage::~QPackage()
{
}

/*!
    Provides an identifier for the package that can be used for many purposes. A URI is the universally unique identification of the package following the IETF URI specification, RFC 2396 http://www.ietf.org/rfc/rfc2396.txt and it must comply with those syntax rules.
 */
QString QPackage::URI() const
{
}

void QPackage::setURI(QString URI)
{
}

/*!
    References the Package that owns this Package.
 */
QPackage *QPackage::nestingPackage() const
{
}

void QPackage::setNestingPackage(QPackage *nestingPackage)
{
}

/*!
    References the PackageMerges that are owned by this Package.
 */
QList<QPackageMerge *> *QPackage::packageMerge() const
{
}

/*!
    Specifies the packageable elements that are owned by this Package.
 */
QList<QPackageableElement *> *QPackage::packagedElement() const
{
}

/*!
    The query makesVisible() defines whether a Package makes an element visible outside itself. Elements with no visibility and elements with public visibility are made visible.
 */
bool QPackage::makesVisible(QNamedElement *el) const
{
}

/*!
    The query mustBeOwned() indicates whether elements of this type must have an owner.
 */
bool QPackage::mustBeOwned() const
{
}

/*!
    Missing derivation for Package::/nestedPackage : Package
 */
QList<QPackage *> *QPackage::nestedPackage() const
{
}

/*!
    Missing derivation for Package::/ownedType : Type
 */
QList<QType *> *QPackage::ownedType() const
{
}

/*!
    The query visibleMembers() defines which members of a Package can be accessed outside it.
 */
QList<QPackageableElement *> *QPackage::visibleMembers() const
{
}

#include "moc_qpackage.cpp"

QT_END_NAMESPACE_UML_CLASSES_KERNEL

