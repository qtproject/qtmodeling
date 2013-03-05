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
#ifndef QTUML_QBEHAVIORALFEATURE_H
#define QTUML_QBEHAVIORALFEATURE_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtWrappedObjects/QWrappedObject>
#include <QtUml/QNamespace>
#include <QtUml/QFeature>

// QtUml includes
#include <QtUml/QtUmlNamespace>

// Qt includes
#include <QtCore/QList>
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QtUml
{

QT_MODULE(QtUml)

// Forward decls for function parameters
class QType;
class QNamedElement;
class QParameterSet;
class QBehavior;
class QParameter;

class QBehavioralFeaturePrivate;

class Q_UML_EXPORT QBehavioralFeature : public QWrappedObject
{
    Q_OBJECT

    Q_PROPERTY(QSet<QtUml::QElement *> ownedElements READ ownedElements)
    Q_PROPERTY(QtUml::QElement * owner READ owner)
    Q_PROPERTY(QSet<QtUml::QComment *> ownedComments READ ownedComments)

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QtUmlNS::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QString qualifiedName READ qualifiedName STORED false)
    Q_PROPERTY(QtUml::QStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(QtUml::QNamespace * namespace_ READ namespace_)
    Q_PROPERTY(QSet<QtUml::QDependency *> clientDependencies READ clientDependencies)

    Q_PROPERTY(QSet<QtUml::QPackageImport *> packageImports READ packageImports)
    Q_PROPERTY(QSet<QtUml::QNamedElement *> members READ members)
    Q_PROPERTY(QSet<QtUml::QPackageableElement *> importedMembers READ importedMembers STORED false)
    Q_PROPERTY(QSet<QtUml::QElementImport *> elementImports READ elementImports)
    Q_PROPERTY(QSet<QtUml::QConstraint *> ownedRules READ ownedRules)
    Q_PROPERTY(QSet<QtUml::QNamedElement *> ownedMembers READ ownedMembers)

    Q_PROPERTY(bool isLeaf READ isLeaf WRITE setLeaf RESET unsetLeaf)
    Q_PROPERTY(QSet<QtUml::QRedefinableElement *> redefinedElements READ redefinedElements)
    Q_PROPERTY(QSet<QtUml::QClassifier *> redefinitionContexts READ redefinitionContexts)

    Q_PROPERTY(bool isStatic READ isStatic WRITE setStatic RESET unsetStatic)
    Q_PROPERTY(QSet<QtUml::QClassifier *> featuringClassifiers READ featuringClassifiers)

    Q_PROPERTY(QtUmlNS::CallConcurrencyKind concurrency READ concurrency WRITE setConcurrency RESET unsetConcurrency)
    Q_PROPERTY(bool isAbstract READ isAbstract WRITE setAbstract RESET unsetAbstract)
    Q_PROPERTY(QSet<QtUml::QType *> raisedExceptions READ raisedExceptions)
    Q_PROPERTY(QList<QtUml::QParameter *> ownedParameters READ ownedParameters)
    Q_PROPERTY(QSet<QtUml::QParameterSet *> ownedParameterSets READ ownedParameterSets)
    Q_PROPERTY(QSet<QtUml::QBehavior *> methods READ methods)

    Q_DISABLE_COPY(QBehavioralFeature)
    Q_DECLARE_PRIVATE(QBehavioralFeature)

public:
    Q_INVOKABLE explicit QBehavioralFeature(QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
    virtual ~QBehavioralFeature();

    // Association ends from aggregated QElement
    Q_INVOKABLE QSet<QElement *> ownedElements() const;
    Q_INVOKABLE QElement *owner() const;
    Q_INVOKABLE QSet<QComment *> ownedComments() const;
    Q_INVOKABLE void addOwnedComment(QComment *ownedComment);
    Q_INVOKABLE void removeOwnedComment(QComment *ownedComment);

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

    // Association ends from aggregated QNamespace
    Q_INVOKABLE QSet<QPackageImport *> packageImports() const;
    Q_INVOKABLE void addPackageImport(QPackageImport *packageImport);
    Q_INVOKABLE void removePackageImport(QPackageImport *packageImport);
    Q_INVOKABLE QSet<QNamedElement *> members() const;
    Q_INVOKABLE QSet<QPackageableElement *> importedMembers() const;
    Q_INVOKABLE QSet<QElementImport *> elementImports() const;
    Q_INVOKABLE void addElementImport(QElementImport *elementImport);
    Q_INVOKABLE void removeElementImport(QElementImport *elementImport);
    Q_INVOKABLE QSet<QConstraint *> ownedRules() const;
    Q_INVOKABLE void addOwnedRule(QConstraint *ownedRule);
    Q_INVOKABLE void removeOwnedRule(QConstraint *ownedRule);
    Q_INVOKABLE QSet<QNamedElement *> ownedMembers() const;

    // Attributes from aggregated QRedefinableElement
    Q_INVOKABLE bool isLeaf() const;
    Q_INVOKABLE void setLeaf(bool isLeaf);
    Q_INVOKABLE void unsetLeaf();

    // Association ends from aggregated QRedefinableElement
    Q_INVOKABLE QSet<QRedefinableElement *> redefinedElements() const;
    Q_INVOKABLE QSet<QClassifier *> redefinitionContexts() const;

    // Attributes from aggregated QFeature
    Q_INVOKABLE bool isStatic() const;
    Q_INVOKABLE void setStatic(bool isStatic);
    Q_INVOKABLE void unsetStatic();

    // Association ends from aggregated QFeature
    Q_INVOKABLE QSet<QClassifier *> featuringClassifiers() const;

    // Attributes from QBehavioralFeature
    Q_INVOKABLE QtUmlNS::CallConcurrencyKind concurrency() const;
    Q_INVOKABLE void setConcurrency(QtUmlNS::CallConcurrencyKind concurrency);
    Q_INVOKABLE void unsetConcurrency();
    Q_INVOKABLE bool isAbstract() const;
    Q_INVOKABLE void setAbstract(bool isAbstract);
    Q_INVOKABLE void unsetAbstract();

    // Association ends from QBehavioralFeature
    Q_INVOKABLE QSet<QType *> raisedExceptions() const;
    Q_INVOKABLE void addRaisedException(QType *raisedException);
    Q_INVOKABLE void removeRaisedException(QType *raisedException);
    Q_INVOKABLE QList<QParameter *> ownedParameters() const;
    Q_INVOKABLE void addOwnedParameter(QParameter *ownedParameter);
    Q_INVOKABLE void removeOwnedParameter(QParameter *ownedParameter);
    Q_INVOKABLE QSet<QParameterSet *> ownedParameterSets() const;
    Q_INVOKABLE void addOwnedParameterSet(QParameterSet *ownedParameterSet);
    Q_INVOKABLE void removeOwnedParameterSet(QParameterSet *ownedParameterSet);
    Q_INVOKABLE QSet<QBehavior *> methods() const;
    Q_INVOKABLE void addMethod(QBehavior *method);
    Q_INVOKABLE void removeMethod(QBehavior *method);

    // Operations
    Q_INVOKABLE bool isDistinguishableFrom(const QNamedElement *n, const QNamespace *ns) const;

    virtual void setPropertyData();

protected:
    explicit QBehavioralFeature(QBehavioralFeaturePrivate &dd, QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);

private:
    QNamespace *_wrappedNamespace;
    QFeature *_wrappedFeature;
};

}

QT_END_NAMESPACE

QT_END_HEADER

#endif // QTUML_QBEHAVIORALFEATURE_H

