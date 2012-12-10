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
#ifndef QTUML_QSIGNALEVENT_H
#define QTUML_QSIGNALEVENT_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtUml/QMessageEvent>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for function parameters
class QSignal;

class QSignalEventPrivate;

class Q_UML_EXPORT QSignalEvent : public QMessageEvent
{
    Q_OBJECT

    Q_PROPERTY(QSignal * signal READ signal WRITE setSignal)

    Q_DISABLE_COPY(QSignalEvent)
    Q_DECLARE_PRIVATE(QSignalEvent)

public:
    Q_INVOKABLE explicit QSignalEvent(QtMof::QMofObject *parent = 0, QtMof::QMofObject *wrapper = 0);
    virtual ~QSignalEvent();

    // Association ends from QSignalEvent
    Q_INVOKABLE QSignal *signal() const;
    Q_INVOKABLE void setSignal(QSignal *signal);

protected:
    explicit QSignalEvent(QSignalEventPrivate &dd, QtMof::QMofObject *parent = 0, QtMof::QMofObject *wrapper = 0);
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE_QTUML(QSignalEvent) *)
Q_DECLARE_METATYPE(const QSet<QT_PREPEND_NAMESPACE_QTUML(QSignalEvent) *> *)
Q_DECLARE_METATYPE(const QList<QT_PREPEND_NAMESPACE_QTUML(QSignalEvent) *> *)

QT_END_HEADER

#endif // QTUML_QSIGNALEVENT_H

