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
#ifndef QTUML_QTEMPLATEPARAMETER_H
#define QTUML_QTEMPLATEPARAMETER_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QElement>

QT_BEGIN_HEADER


QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

class QTemplateParameterPrivate;
class QParameterableElement;
class QTemplateSignature;

class Q_UML_EXPORT QTemplateParameter : public QObject, public QElement
{
    Q_OBJECT

    // From QElement
    Q_PROPERTY(const QSet<QComment *> * ownedComments READ ownedComments)
    Q_PROPERTY(const QSet<QElement *> * ownedElements READ ownedElements)
    Q_PROPERTY(QElement * owner READ owner)

    // From QTemplateParameter
    Q_PROPERTY(QParameterableElement * default_ READ default_ WRITE setDefault_)
    Q_PROPERTY(QParameterableElement * ownedDefault READ ownedDefault WRITE setOwnedDefault)
    Q_PROPERTY(QParameterableElement * ownedParameteredElement READ ownedParameteredElement WRITE setOwnedParameteredElement)
    Q_PROPERTY(QParameterableElement * parameteredElement READ parameteredElement WRITE setParameteredElement)
    Q_PROPERTY(QTemplateSignature * signature READ signature WRITE setSignature)

public:
    explicit QTemplateParameter(QObject *parent = 0);
    virtual ~QTemplateParameter();

    // Association-ends (except those derived && !derivedUnion)
    QParameterableElement *default_() const;
    void setDefault_(const QParameterableElement *default_);
    QParameterableElement *ownedDefault() const;
    void setOwnedDefault(const QParameterableElement *ownedDefault);
    QParameterableElement *ownedParameteredElement() const;
    void setOwnedParameteredElement(const QParameterableElement *ownedParameteredElement);
    QParameterableElement *parameteredElement() const;
    void setParameteredElement(const QParameterableElement *parameteredElement);
    QTemplateSignature *signature() const;
    void setSignature(const QTemplateSignature *signature);

private:
    Q_DISABLE_COPY(QTemplateParameter)
    Q_DECLARE_PRIVATE(QTemplateParameter)
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QList<QtUml::QTemplateParameter *>)
Q_DECLARE_METATYPE(QList<QtUml::QTemplateParameter *> *)

QT_END_HEADER

#endif // QTUML_QTEMPLATEPARAMETER_H

