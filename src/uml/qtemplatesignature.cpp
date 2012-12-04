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

#include "qtemplatesignature.h"
#include "qtemplatesignature_p.h"

#include <QtUml/QTemplateParameter>
#include <QtUml/QTemplateableElement>

QT_BEGIN_NAMESPACE_QTUML

QTemplateSignaturePrivate::QTemplateSignaturePrivate() :
    parameters(new QList<QTemplateParameter *>),
    template_(0),
    ownedParameters(new QList<QTemplateParameter *>)
{
}

QTemplateSignaturePrivate::~QTemplateSignaturePrivate()
{
    delete parameters;
    delete ownedParameters;
}

/*!
    \class QTemplateSignature

    \inmodule QtUml

    \brief A template signature bundles the set of formal template parameters for a templated element.
 */

QTemplateSignature::QTemplateSignature(QUmlObject *parent, QUmlObject *wrapper) :
    QElement(*new QTemplateSignaturePrivate, parent, wrapper)
{
}

QTemplateSignature::QTemplateSignature(QTemplateSignaturePrivate &dd, QUmlObject *parent, QUmlObject *wrapper) :
    QElement(dd, parent, wrapper)
{
}

QTemplateSignature::~QTemplateSignature()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QTemplateSignature
// ---------------------------------------------------------------

/*!
    The ordered set of all formal template parameters for this template signature.
 */
const QList<QTemplateParameter *> *QTemplateSignature::parameters() const
{
    // This is a read-write association end

    Q_D(const QTemplateSignature);
    return d->parameters;
}

void QTemplateSignature::addParameter(QTemplateParameter *parameter)
{
    // This is a read-write association end

    Q_D(QTemplateSignature);
    if (!d->parameters->contains(parameter)) {
        d->parameters->append(parameter);
    }
}

void QTemplateSignature::removeParameter(QTemplateParameter *parameter)
{
    // This is a read-write association end

    Q_D(QTemplateSignature);
    if (d->parameters->contains(parameter)) {
        d->parameters->removeAll(parameter);
    }
}

/*!
    The element that owns this template signature.
 */
QTemplateableElement *QTemplateSignature::template_() const
{
    // This is a read-write association end

    Q_D(const QTemplateSignature);
    return d->template_;
}

void QTemplateSignature::setTemplate_(QTemplateableElement *template_)
{
    // This is a read-write association end

    Q_D(QTemplateSignature);
    if (d->template_ != template_) {
        // Adjust opposite property

        d->template_ = template_;

        // Adjust subsetted property(ies)
        (qumlobject_cast<QElementPrivate *>(d))->setOwner(qumlobject_cast<QElement *>(template_));

        // Adjust opposite property
        template_->setOwnedTemplateSignature(this);
    }
}

/*!
    The formal template parameters that are owned by this template signature.
 */
const QList<QTemplateParameter *> *QTemplateSignature::ownedParameters() const
{
    // This is a read-write association end

    Q_D(const QTemplateSignature);
    return d->ownedParameters;
}

void QTemplateSignature::addOwnedParameter(QTemplateParameter *ownedParameter)
{
    // This is a read-write association end

    Q_D(QTemplateSignature);
    if (!d->ownedParameters->contains(ownedParameter)) {
        d->ownedParameters->append(ownedParameter);

        // Adjust subsetted property(ies)
        (qumlobject_cast<QTemplateSignature *>(this))->addParameter(qumlobject_cast<QTemplateParameter *>(ownedParameter));
        (qumlobject_cast<QElementPrivate *>(d))->addOwnedElement(qumlobject_cast<QElement *>(ownedParameter));

        // Adjust opposite property
        ownedParameter->setSignature(this);
    }
}

void QTemplateSignature::removeOwnedParameter(QTemplateParameter *ownedParameter)
{
    // This is a read-write association end

    Q_D(QTemplateSignature);
    if (d->ownedParameters->contains(ownedParameter)) {
        d->ownedParameters->removeAll(ownedParameter);
        ownedParameter->setParent(0);

        // Adjust subsetted property(ies)
        (qumlobject_cast<QTemplateSignature *>(this))->removeParameter(qumlobject_cast<QTemplateParameter *>(ownedParameter));
        (qumlobject_cast<QElementPrivate *>(d))->removeOwnedElement(qumlobject_cast<QElement *>(ownedParameter));

        // Adjust opposite property
        ownedParameter->setSignature(0);
    }
}

#include "moc_qtemplatesignature.cpp"

QT_END_NAMESPACE_QTUML

