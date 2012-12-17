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

#include "qvariableaction.h"
#include "qvariableaction_p.h"

#include <QtUml/QVariable>

QT_BEGIN_NAMESPACE_QTUML

QVariableActionPrivate::QVariableActionPrivate() :
    variable(0)
{
}

QVariableActionPrivate::~QVariableActionPrivate()
{
}

/*!
    \class QVariableAction

    \inmodule QtUml

    \brief VariableAction is an abstract class for actions that operate on a statically specified variable.
 */

QVariableAction::QVariableAction(QWrappedObject *parent, QWrappedObject *wrapper) :
    QAction(*new QVariableActionPrivate, parent, wrapper)
{
}

QVariableAction::QVariableAction(QVariableActionPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QAction(dd, parent, wrapper)
{
}

QVariableAction::~QVariableAction()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QVariableAction
// ---------------------------------------------------------------

/*!
    Variable to be read.
 */
QVariable *QVariableAction::variable() const
{
    // This is a read-write association end

    Q_D(const QVariableAction);
    return d->variable;
}

void QVariableAction::setVariable(QVariable *variable)
{
    // This is a read-write association end

    Q_D(QVariableAction);
    if (d->variable != variable) {
        d->variable = variable;
    }
}

void QVariableAction::registerMetaTypes() const
{
    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QVariableAction) *>("QT_PREPEND_NAMESPACE_QTUML(QVariableAction) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QVariableAction) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QVariableAction) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QVariableAction) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QVariableAction) *> *");
    qRegisterMetaType<QVariableAction *>("QVariableAction *");
    qRegisterMetaType<const QSet<QVariableAction *> *>("const QSet<QVariableAction *> *");
    qRegisterMetaType<const QList<QVariableAction *> *>("const QList<QVariableAction *> *");

    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QVariable) *>("QT_PREPEND_NAMESPACE_QTUML(QVariable) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QVariable) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QVariable) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QVariable) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QVariable) *> *");
    qRegisterMetaType<QVariable *>("QVariable *");
    qRegisterMetaType<const QSet<QVariable *> *>("const QSet<QVariable *> *");
    qRegisterMetaType<const QList<QVariable *> *>("const QList<QVariable *> *");

    QAction::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qvariableaction.cpp"

QT_END_NAMESPACE_QTUML

