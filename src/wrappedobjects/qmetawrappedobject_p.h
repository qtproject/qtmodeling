/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtWrappedObjects module of the Qt Toolkit.
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
** rights. These rights are described in the Nokia  LGPL Exception
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
#ifndef QTWRAPPEDOBJECTS_QMETAWRAPPEDOBJECT_P_H
#define QTWRAPPEDOBJECTS_QMETAWRAPPEDOBJECT_P_H

#include "QtWrappedObjects/QMetaWrappedObject"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTWRAPPEDOBJECTS

QT_MODULE(QtWrappedObjects)

class Q_WRAPPEDOBJECTS_EXPORT QMetaWrappedObjectPrivate
{
    Q_DECLARE_PUBLIC(QMetaWrappedObject)

public:
    explicit QMetaWrappedObjectPrivate();
    virtual ~QMetaWrappedObjectPrivate();

    QMetaWrappedObject *q_ptr;
    const QWrappedObject *wrappedObject;
    QList<QMetaPropertyInfo> propertyInfos;
    QList<QPair<QString, int>> propertyGroupInfos;
};

QT_END_NAMESPACE_QTWRAPPEDOBJECTS

QT_END_HEADER

#endif // QTWRAPPEDOBJECTS_QMETAWRAPPEDOBJECT_P_H
