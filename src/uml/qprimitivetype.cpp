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

#include "qprimitivetype.h"
#include "qprimitivetype_p.h"

#include <QtWrappedObjects/QtWrappedObjectsEnumerations>

QT_BEGIN_NAMESPACE_QTUML

QPrimitiveTypePrivate::QPrimitiveTypePrivate()
{
}

QPrimitiveTypePrivate::~QPrimitiveTypePrivate()
{
}

/*!
    \class QPrimitiveType

    \inmodule QtUml

    \brief A primitive type defines a predefined data type, without any relevant substructure (i.e., it has no parts in the context of UML). A primitive datatype may have an algebra and operations defined outside of UML, for example, mathematically.
 */

QPrimitiveType::QPrimitiveType(QWrappedObject *parent, QWrappedObject *wrapper) :
    QDataType(*new QPrimitiveTypePrivate, parent, wrapper)
{
    setPropertyData();
}

QPrimitiveType::QPrimitiveType(QPrimitiveTypePrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QDataType(dd, parent, wrapper)
{
    setPropertyData();
}

QPrimitiveType::~QPrimitiveType()
{
}

void QPrimitiveType::registerMetaTypes() const
{
    QDataType::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

void QPrimitiveType::setPropertyData()
{
    QDataType::setPropertyData();
}

#include "moc_qprimitivetype.cpp"

QT_END_NAMESPACE_QTUML

