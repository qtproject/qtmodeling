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
#ifndef QTUML_QVARIABLE_H
#define QTUML_QVARIABLE_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtWrappedObjects/QWrappedObject>
#include <QtUml/QMultiplicityElement>
#include <QtUml/QConnectableElement>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QtUml
{

QT_MODULE(QtUml)

// Forward decls for function parameters
class QActivity;
class QStructuredActivityNode;
class QAction;

class QVariablePrivate;

class Q_UML_EXPORT QVariable : public QWrappedObject
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

    Q_PROPERTY(QtUml::QStructuredActivityNode * scope READ scope WRITE setScope)
    Q_PROPERTY(QtUml::QActivity * activityScope READ activityScope WRITE setActivityScope)

    Q_DISABLE_COPY(QVariable)
    Q_DECLARE_PRIVATE(QVariable)

public:
    Q_INVOKABLE explicit QVariable(QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
    virtual ~QVariable();

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

    // Association ends from QVariable
    Q_INVOKABLE QStructuredActivityNode *scope() const;
    Q_INVOKABLE void setScope(QStructuredActivityNode *scope);
    Q_INVOKABLE QActivity *activityScope() const;
    Q_INVOKABLE void setActivityScope(QActivity *activityScope);

    // Operations
    Q_INVOKABLE bool isAccessibleBy(const QAction *a) const;

    virtual void setPropertyData();

protected:
    explicit QVariable(QVariablePrivate &dd, QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);

private:
    QMultiplicityElement *_wrappedMultiplicityElement;
    QConnectableElement *_wrappedConnectableElement;
};

}

QT_END_NAMESPACE

QT_END_HEADER

#endif // QTUML_QVARIABLE_H

