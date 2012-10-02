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
#ifndef QTUML_QTRANSITION_H
#define QTUML_QTRANSITION_H

#include <QtUml/QtUmlGlobal>

// QtUml includes
#include <QtUml/QtUmlEnumerations>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QRedefinableElement>
#include <QtUml/QNamespace>

// Qt includes
#include <QtCore/QList>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

class QTransitionPrivate;
class QTrigger;
class QVertex;
class QStateMachine;
class QClassifier;
class QBehavior;
class QRegion;
class QConstraint;

class Q_UML_EXPORT QTransition : public QObject, public QRedefinableElement, public QNamespace
{
    Q_OBJECT

    // From QElement
    Q_PROPERTY(QList<QComment *> * ownedComments READ ownedComments)
    Q_PROPERTY(const QList<QElement *> * ownedElements READ ownedElements)
    Q_PROPERTY(const QElement * owner READ owner)

    // From QNamedElement
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString qualifiedName READ qualifiedName)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QList<QDependency *> * clientDependencies READ clientDependencies)
    Q_PROPERTY(QStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(const QNamespace * namespace_ READ namespace_)

    // From QRedefinableElement
    Q_PROPERTY(bool isLeaf READ isLeaf WRITE setLeaf)
    Q_PROPERTY(const QList<QRedefinableElement *> * redefinedElements READ redefinedElements)
    Q_PROPERTY(const QList<QClassifier *> * redefinitionContexts READ redefinitionContexts)

    // From QNamespace
    Q_PROPERTY(QList<QElementImport *> * elementImports READ elementImports)
    Q_PROPERTY(const QList<QPackageableElement *> * importedMembers READ importedMembers)
    Q_PROPERTY(const QList<QNamedElement *> * members READ members)
    Q_PROPERTY(const QList<QNamedElement *> * ownedMembers READ ownedMembers)
    Q_PROPERTY(QList<QConstraint *> * ownedRules READ ownedRules)
    Q_PROPERTY(QList<QPackageImport *> * packageImports READ packageImports)

    // From QTransition
    Q_PROPERTY(QtUml::TransitionKind kind READ kind WRITE setKind)
    Q_PROPERTY(QRegion * container READ container WRITE setContainer)
    Q_PROPERTY(QBehavior * effect READ effect WRITE setEffect)
    Q_PROPERTY(QConstraint * guard READ guard WRITE setGuard)
    Q_PROPERTY(QTransition * redefinedTransition READ redefinedTransition WRITE setRedefinedTransition)
    Q_PROPERTY(const QClassifier * redefinitionContext READ redefinitionContext)
    Q_PROPERTY(QVertex * source READ source WRITE setSource)
    Q_PROPERTY(QVertex * target READ target WRITE setTarget)
    Q_PROPERTY(QList<QTrigger *> * triggers READ triggers)

public:
    explicit QTransition(QObject *parent = 0);
    virtual ~QTransition();

    // Attributes (except those derived && !derivedUnion)
    QtUml::TransitionKind kind() const;
    void setKind(QtUml::TransitionKind kind);

    // Association-ends (except those derived && !derivedUnion)
    QRegion *container() const;
    void setContainer(QRegion *container);
    QBehavior *effect() const;
    void setEffect(QBehavior *effect);
    QConstraint *guard() const;
    void setGuard(QConstraint *guard);
    QTransition *redefinedTransition() const;
    void setRedefinedTransition(QTransition *redefinedTransition);
    QVertex *source() const;
    void setSource(QVertex *source);
    QVertex *target() const;
    void setTarget(QVertex *target);
    QList<QTrigger *> *triggers();

    // Operations (including accessors for derived && !derivedUnion attributes and association-ends)
    const QStateMachine *containingStateMachine() const;
    bool isConsistentWith(const QRedefinableElement *redefinee) const;
    const QClassifier *redefinitionContext() const;

private:
    Q_DISABLE_COPY(QTransition)
    Q_DECLARE_PRIVATE(QTransition)
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QList<QtUml::QTransition *>)
Q_DECLARE_METATYPE(QList<QtUml::QTransition *> *)

QT_END_HEADER

#endif // QTUML_QTRANSITION_H

