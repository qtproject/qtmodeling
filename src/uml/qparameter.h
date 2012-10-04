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
#ifndef QTUML_QPARAMETER_H
#define QTUML_QPARAMETER_H

#include <QtUml/QtUmlGlobal>

// QtUml includes
#include <QtUml/QtUmlEnumerations>
#include <QtUml/QtUmlEnumerations>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QMultiplicityElement>
#include <QtUml/QConnectableElement>

// Qt includes
#include <QtCore/QString>
#include <QtCore/QSet>

QT_BEGIN_HEADER


QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

class QParameterPrivate;
class QValueSpecification;
class QOperation;
class QParameterSet;

class Q_UML_EXPORT QParameter : public QObject, public QMultiplicityElement, public QConnectableElement
{
    Q_OBJECT

    // From QElement
    Q_PROPERTY(const QSet<QComment *> * ownedComments READ ownedComments)
    Q_PROPERTY(const QSet<QElement *> * ownedElements READ ownedElements)
    Q_PROPERTY(QElement * owner READ owner)

    // From QMultiplicityElement
    Q_PROPERTY(bool isOrdered READ isOrdered WRITE setOrdered)
    Q_PROPERTY(bool isUnique READ isUnique WRITE setUnique)
    Q_PROPERTY(qint32 lower READ lower)
    Q_PROPERTY(qint32 upper READ upper)
    Q_PROPERTY(QValueSpecification * lowerValue READ lowerValue WRITE setLowerValue)
    Q_PROPERTY(QValueSpecification * upperValue READ upperValue WRITE setUpperValue)

    // From QNamedElement
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString qualifiedName READ qualifiedName)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(const QSet<QDependency *> * clientDependencies READ clientDependencies)
    Q_PROPERTY(QStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(QNamespace * namespace_ READ namespace_)

    // From QTypedElement
    Q_PROPERTY(QType * type READ type WRITE setType)

    // From QParameterableElement
    Q_PROPERTY(QTemplateParameter * owningTemplateParameter READ owningTemplateParameter WRITE setOwningTemplateParameter)

    // From QConnectableElement
    Q_PROPERTY(const QList<QConnectorEnd *> * ends READ ends)
    Q_PROPERTY(QConnectableElementTemplateParameter * templateParameter READ templateParameter WRITE setTemplateParameter)

    // From QParameter
    Q_PROPERTY(QString default_ READ default_)
    Q_PROPERTY(QtUml::ParameterDirectionKind direction READ direction WRITE setDirection)
    Q_PROPERTY(QtUml::ParameterEffectKind effect READ effect WRITE setEffect)
    Q_PROPERTY(bool isException READ isException WRITE setException)
    Q_PROPERTY(bool isStream READ isStream WRITE setStream)
    Q_PROPERTY(QValueSpecification * defaultValue READ defaultValue WRITE setDefaultValue)
    Q_PROPERTY(QOperation * operation READ operation WRITE setOperation)
    Q_PROPERTY(const QSet<QParameterSet *> * parameterSets READ parameterSets)

public:
    explicit QParameter(QObject *parent = 0);
    virtual ~QParameter();

    // Attributes (except those derived && !derivedUnion)
    QtUml::ParameterDirectionKind direction() const;
    void setDirection(QtUml::ParameterDirectionKind direction);
    QtUml::ParameterEffectKind effect() const;
    void setEffect(QtUml::ParameterEffectKind effect);
    bool isException() const;
    void setException(bool isException);
    bool isStream() const;
    void setStream(bool isStream);

    // Association-ends (except those derived && !derivedUnion)
    QValueSpecification *defaultValue() const;
    void setDefaultValue(const QValueSpecification *defaultValue);
    QOperation *operation() const;
    void setOperation(const QOperation *operation);
    const QSet<QParameterSet *> *parameterSets() const;
    void addParameterSet(const QParameterSet *parameterSet);
    void removeParameterSet(const QParameterSet *parameterSet);

    // Operations (including accessors for derived && !derivedUnion attributes and association-ends)
    QString default_() const;

private:
    Q_DISABLE_COPY(QParameter)
    Q_DECLARE_PRIVATE(QParameter)
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QList<QtUml::QParameter *>)
Q_DECLARE_METATYPE(QList<QtUml::QParameter *> *)

QT_END_HEADER

#endif // QTUML_QPARAMETER_H

