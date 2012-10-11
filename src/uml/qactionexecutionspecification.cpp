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

#include "qactionexecutionspecification.h"
#include "qactionexecutionspecification_p.h"

#include <QtUml/QAction>

QT_BEGIN_NAMESPACE_QTUML

QActionExecutionSpecificationPrivate::QActionExecutionSpecificationPrivate() :
    action(0)
{
}

QActionExecutionSpecificationPrivate::~QActionExecutionSpecificationPrivate()
{
}

void QActionExecutionSpecificationPrivate::setAction(const QAction *action)
{
    this->action = const_cast<QAction *>(action);
}

/*!
    \class QActionExecutionSpecification

    \inmodule QtUml

    \brief An action execution specification is a kind of execution specification representing the execution of an action.
 */

QActionExecutionSpecification::QActionExecutionSpecification(QObject *parent)
    : QObject(parent)
{
    d_umlptr = new QActionExecutionSpecificationPrivate;
}

QActionExecutionSpecification::QActionExecutionSpecification(bool createPimpl, QObject *parent)
    : QObject(parent)
{
    if (createPimpl)
        d_umlptr = new QActionExecutionSpecificationPrivate;
}

QActionExecutionSpecification::~QActionExecutionSpecification()
{
}

/*!
    Action whose execution is occurring.
 */
QAction *QActionExecutionSpecification::action() const
{
    QTUML_D(const QActionExecutionSpecification);
    return d->action;
}

void QActionExecutionSpecification::setAction(const QAction *action)
{
    QTUML_D(QActionExecutionSpecification);
    d->setAction(const_cast<QAction *>(action));
}

#include "moc_qactionexecutionspecification.cpp"

QT_END_NAMESPACE_QTUML
