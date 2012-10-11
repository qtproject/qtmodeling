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

#include "qextensionpoint.h"
#include "qextensionpoint_p.h"
#include "qnamedelement_p.h"

#include <QtUml/QUseCase>

QT_BEGIN_NAMESPACE_QTUML

QExtensionPointPrivate::QExtensionPointPrivate() :
    useCase(0)
{
}

QExtensionPointPrivate::~QExtensionPointPrivate()
{
}

void QExtensionPointPrivate::setUseCase(const QUseCase *useCase)
{
    this->useCase = const_cast<QUseCase *>(useCase);

    // Adjust subsetted property(ies)
    setNamespace_(useCase);
}

/*!
    \class QExtensionPoint

    \inmodule QtUml

    \brief An extension point identifies a point in the behavior of a use case where that behavior can be extended by the behavior of some other (extending) use case, as specified by an extend relationship.
 */

QExtensionPoint::QExtensionPoint(QObject *parent)
    : QObject(parent)
{
    d_umlptr = new QExtensionPointPrivate;
}

QExtensionPoint::QExtensionPoint(bool createPimpl, QObject *parent)
    : QObject(parent)
{
    if (createPimpl)
        d_umlptr = new QExtensionPointPrivate;
}

QExtensionPoint::~QExtensionPoint()
{
}

/*!
    References the use case that owns this extension point.
 */
QUseCase *QExtensionPoint::useCase() const
{
    QTUML_D(const QExtensionPoint);
    return d->useCase;
}

void QExtensionPoint::setUseCase(const QUseCase *useCase)
{
    QTUML_D(QExtensionPoint);
    d->setUseCase(const_cast<QUseCase *>(useCase));
}

#include "moc_qextensionpoint.cpp"

QT_END_NAMESPACE_QTUML
