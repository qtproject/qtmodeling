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

// Base class includes
#include <QtWrappedObjects/QWrappedObject>
#include <QtUml/QMultiplicityElement>
#include <QtUml/QConnectableElement>

// QtUml includes
#include <QtUml/QtUmlNamespace>
#include <QtUml/QtUmlNamespace>

// Qt includes
#include <QtCore/QString>
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QtUml
{

QT_MODULE(QtUml)

// Forward decls for function parameters
class QValueSpecification;
class QOperation;
class QParameterSet;

class QParameterPrivate;

class Q_UML_EXPORT QParameter : public QWrappedObject
{
    Q_OBJECT

    Q_PROPERTY(QSet<QtUml::QElement *> ownedElements READ ownedElements)
    Q_PROPERTY(QtUml::QElement * owner READ owner)
    Q_PROPERTY(QSet<QtUml::QComment *> ownedComments READ ownedComments)

    Q_PROPERTY(qint32 upper READ upper WRITE setUpper RESET unsetUpper STORED false)
    Q_PROPERTY(bool isUnique READ isUnique WRITE setUnique RESET unsetUnique)
    Q_PROPERTY(bool isOrdered READ isOrdered WRITE setOrdered RESET unsetOrdered)
    Q_PROPERTY(qint32 lower READ lower WRITE setLower STORED false)
    Q_PROPERTY(QtUml::QValueSpecification * upperValue READ upperValue WRITE setUpperValue)
    Q_PROPERTY(QtUml::QValueSpecification * lowerValue READ lowerValue WRITE setLowerValue)

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QtUmlNS::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QString qualifiedName READ qualifiedName STORED false)
    Q_PROPERTY(QtUml::QStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(QtUml::QNamespace * namespace_ READ namespace_)
    Q_PROPERTY(QSet<QtUml::QDependency *> clientDependencies READ clientDependencies)

    Q_PROPERTY(QtUml::QType * type READ type WRITE setType)

    Q_PROPERTY(QtUml::QTemplateParameter * owningTemplateParameter READ owningTemplateParameter WRITE setOwningTemplateParameter)

    Q_PROPERTY(QList<QtUml::QConnectorEnd *> ends READ ends STORED false)
    Q_PROPERTY(QtUml::QConnectableElementTemplateParameter * templateParameter READ templateParameter WRITE setTemplateParameter)

    Q_PROPERTY(bool isException READ isException WRITE setException RESET unsetException)
    Q_PROPERTY(QString default_ READ default_ WRITE setDefault_ STORED false)
    Q_PROPERTY(QtUmlNS::ParameterDirectionKind direction READ direction WRITE setDirection RESET unsetDirection)
    Q_PROPERTY(bool isStream READ isStream WRITE setStream RESET unsetStream)
    Q_PROPERTY(QtUmlNS::ParameterEffectKind effect READ effect WRITE setEffect)
    Q_PROPERTY(QtUml::QOperation * operation READ operation WRITE setOperation)
    Q_PROPERTY(QtUml::QValueSpecification * defaultValue READ defaultValue WRITE setDefaultValue)
    Q_PROPERTY(QSet<QtUml::QParameterSet *> parameterSets READ parameterSets)

    Q_DISABLE_COPY(QParameter)
    Q_DECLARE_PRIVATE(QParameter)

public:
    Q_INVOKABLE explicit QParameter(QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
    virtual ~QParameter();

    // Association ends from aggregated QElement
    Q_INVOKABLE QSet<QElement *> ownedElements() const;
    Q_INVOKABLE QElement *owner() const;
    Q_INVOKABLE QSet<QComment *> ownedComments() const;
    Q_INVOKABLE void addOwnedComment(QComment *ownedComment);
    Q_INVOKABLE void removeOwnedComment(QComment *ownedComment);

    // Attributes from aggregated QMultiplicityElement
    Q_INVOKABLE qint32 upper() const;
    Q_INVOKABLE void setUpper(qint32 upper);
    Q_INVOKABLE void unsetUpper();
    Q_INVOKABLE bool isUnique() const;
    Q_INVOKABLE void setUnique(bool isUnique);
    Q_INVOKABLE void unsetUnique();
    Q_INVOKABLE bool isOrdered() const;
    Q_INVOKABLE void setOrdered(bool isOrdered);
    Q_INVOKABLE void unsetOrdered();
    Q_INVOKABLE qint32 lower() const;
    Q_INVOKABLE void setLower(qint32 lower);

    // Association ends from aggregated QMultiplicityElement
    Q_INVOKABLE QValueSpecification *upperValue() const;
    Q_INVOKABLE void setUpperValue(QValueSpecification *upperValue);
    Q_INVOKABLE QValueSpecification *lowerValue() const;
    Q_INVOKABLE void setLowerValue(QValueSpecification *lowerValue);

    // Attributes from aggregated QNamedElement
    Q_INVOKABLE QString name() const;
    Q_INVOKABLE void setName(QString name);
    Q_INVOKABLE QtUmlNS::VisibilityKind visibility() const;
    Q_INVOKABLE void setVisibility(QtUmlNS::VisibilityKind visibility);
    Q_INVOKABLE QString qualifiedName() const;

    // Association ends from aggregated QNamedElement
    Q_INVOKABLE QStringExpression *nameExpression() const;
    Q_INVOKABLE void setNameExpression(QStringExpression *nameExpression);
    Q_INVOKABLE QNamespace *namespace_() const;
    Q_INVOKABLE QSet<QDependency *> clientDependencies() const;
    Q_INVOKABLE void addClientDependency(QDependency *clientDependency);
    Q_INVOKABLE void removeClientDependency(QDependency *clientDependency);

    // Association ends from aggregated QTypedElement
    Q_INVOKABLE QType *type() const;
    Q_INVOKABLE void setType(QType *type);

    // Association ends from aggregated QParameterableElement
    Q_INVOKABLE QTemplateParameter *owningTemplateParameter() const;
    Q_INVOKABLE void setOwningTemplateParameter(QTemplateParameter *owningTemplateParameter);

    // Association ends from aggregated QConnectableElement
    Q_INVOKABLE QList<QConnectorEnd *> ends() const;
    Q_INVOKABLE QConnectableElementTemplateParameter *templateParameter() const;
    Q_INVOKABLE void setTemplateParameter(QConnectableElementTemplateParameter *templateParameter);

    // Attributes from QParameter
    Q_INVOKABLE bool isException() const;
    Q_INVOKABLE void setException(bool isException);
    Q_INVOKABLE void unsetException();
    Q_INVOKABLE QString default_() const;
    Q_INVOKABLE void setDefault_(QString default_);
    Q_INVOKABLE QtUmlNS::ParameterDirectionKind direction() const;
    Q_INVOKABLE void setDirection(QtUmlNS::ParameterDirectionKind direction);
    Q_INVOKABLE void unsetDirection();
    Q_INVOKABLE bool isStream() const;
    Q_INVOKABLE void setStream(bool isStream);
    Q_INVOKABLE void unsetStream();
    Q_INVOKABLE QtUmlNS::ParameterEffectKind effect() const;
    Q_INVOKABLE void setEffect(QtUmlNS::ParameterEffectKind effect);

    // Association ends from QParameter
    Q_INVOKABLE QOperation *operation() const;
    Q_INVOKABLE void setOperation(QOperation *operation);
    Q_INVOKABLE QValueSpecification *defaultValue() const;
    Q_INVOKABLE void setDefaultValue(QValueSpecification *defaultValue);
    Q_INVOKABLE QSet<QParameterSet *> parameterSets() const;
    Q_INVOKABLE void addParameterSet(QParameterSet *parameterSet);
    Q_INVOKABLE void removeParameterSet(QParameterSet *parameterSet);

    virtual void setPropertyData();

protected:
    explicit QParameter(QParameterPrivate &dd, QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);

private:
    QMultiplicityElement *_wrappedMultiplicityElement;
    QConnectableElement *_wrappedConnectableElement;
};

}

QT_END_NAMESPACE

QT_END_HEADER

#endif // QTUML_QPARAMETER_H

