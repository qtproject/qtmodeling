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
#ifndef QTMOF_QMOFOBJECT_H
#define QTMOF_QMOFOBJECT_H

#include <QtMof/QtMofGlobal>

// Base class includes
#include <QtWrappedObjects/QWrappedObject>

// Qt includes
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QtMof
{

QT_MODULE(QtMof)

// Forward decls for function parameters
class QArgument;
class QOperation;
class QProperty;

class QMofObjectPrivate;

class Q_MOF_EXPORT QMofObject : public QWrappedObject
{
    Q_OBJECT

    Q_DISABLE_COPY(QMofObject)
    Q_DECLARE_PRIVATE(QMofObject)

public:
    Q_INVOKABLE explicit QMofObject(QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
    virtual ~QMofObject();

    // Operations
    Q_INVOKABLE QMofObject *get(const QProperty *property) const;
    Q_INVOKABLE bool equals(const QMofObject *element) const;
    Q_INVOKABLE void set(const QProperty *property, const QMofObject *value);
    Q_INVOKABLE bool isSet(const QProperty *property) const;
    Q_INVOKABLE void unset(const QProperty *property);
    Q_INVOKABLE QMofObject *invoke(const QOperation *op, QSet<QArgument *> arguments);

    virtual void setPropertyData();

protected:
    explicit QMofObject(QMofObjectPrivate &dd, QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
};

}

QT_END_NAMESPACE

QT_END_HEADER

#endif // QTMOF_QMOFOBJECT_H

