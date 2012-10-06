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

#include "qstructuralfeatureaction.h"

#include <QtUml/QInputPin>
#include <QtUml/QStructuralFeature>

QT_BEGIN_NAMESPACE_QTUML

class QStructuralFeatureActionPrivate
{
public:
    explicit QStructuralFeatureActionPrivate();
    virtual ~QStructuralFeatureActionPrivate();

    QInputPin *object;
    QStructuralFeature *structuralFeature;
};

QStructuralFeatureActionPrivate::QStructuralFeatureActionPrivate()
{
}

QStructuralFeatureActionPrivate::~QStructuralFeatureActionPrivate()
{
}

/*!
    \class QStructuralFeatureAction

    \inmodule QtUml

    \brief StructuralFeatureAction is an abstract class for all structural feature actions.
 */

QStructuralFeatureAction::QStructuralFeatureAction()
    : d_ptr(new QStructuralFeatureActionPrivate)
{
}

QStructuralFeatureAction::~QStructuralFeatureAction()
{
    delete d_ptr;
}

/*!
    Gives the input pin from which the object whose structural feature is to be read or written is obtained.
 */
QInputPin *QStructuralFeatureAction::object() const
{
    return d_ptr->object;
}

void QStructuralFeatureAction::setObject(const QInputPin *object)
{
    d_ptr->object = const_cast<QInputPin *>(object);
}

/*!
    Structural feature to be read.
 */
QStructuralFeature *QStructuralFeatureAction::structuralFeature() const
{
    return d_ptr->structuralFeature;
}

void QStructuralFeatureAction::setStructuralFeature(const QStructuralFeature *structuralFeature)
{
    d_ptr->structuralFeature = const_cast<QStructuralFeature *>(structuralFeature);
}

QT_END_NAMESPACE_QTUML

