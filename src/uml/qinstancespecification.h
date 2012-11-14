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
#ifndef QTUML_QINSTANCESPECIFICATION_H
#define QTUML_QINSTANCESPECIFICATION_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QDeployedArtifact>
#include <QtUml/QPackageableElement>
#include <QtUml/QDeploymentTarget>

// Qt includes
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for function parameters
class QClassifier;
class QSlot;
class QValueSpecification;

class QInstanceSpecificationPrivate;

class Q_UML_EXPORT QInstanceSpecification : public QObject
{
    Q_OBJECT

    Q_PROPERTY(const QSet<QClassifier *> * classifiers READ classifiers)
    Q_PROPERTY(QValueSpecification * specification READ specification WRITE setSpecification)
    Q_PROPERTY(const QSet<QSlot *> * slots_ READ slots_)

    Q_DISABLE_COPY(QInstanceSpecification)
    Q_DECLARE_PRIVATE(QInstanceSpecification)

public:
    explicit QInstanceSpecification(QObject *parent = 0);
    virtual ~QInstanceSpecification();

    // Association ends from aggregated QElement
    const QSet<QElement *> *ownedElements() const;
    QElement *owner() const;
    const QSet<QComment *> *ownedComments() const;
    void addOwnedComment(QComment *ownedComment);
    void removeOwnedComment(QComment *ownedComment);

    // Attributes from aggregated QNamedElement
    QString name() const;
    void setName(QString name);
    QString qualifiedName() const;

    // Association ends from aggregated QNamedElement
    QStringExpression *nameExpression() const;
    void setNameExpression(QStringExpression *nameExpression);
    QNamespace *namespace_() const;
    const QSet<QDependency *> *clientDependencies() const;
    void addClientDependency(QDependency *clientDependency);
    void removeClientDependency(QDependency *clientDependency);

    // Association ends from aggregated QParameterableElement
    QTemplateParameter *owningTemplateParameter() const;
    void setOwningTemplateParameter(QTemplateParameter *owningTemplateParameter);
    QTemplateParameter *templateParameter() const;
    void setTemplateParameter(QTemplateParameter *templateParameter);

    // Attributes from aggregated QPackageableElement
    QtUml::VisibilityKind visibility() const;
    void setVisibility(QtUml::VisibilityKind visibility);

    // Association ends from aggregated QDeploymentTarget
    const QSet<QPackageableElement *> *deployedElements() const;
    const QSet<QDeployment *> *deployments() const;
    void addDeployment(QDeployment *deployment);
    void removeDeployment(QDeployment *deployment);

    // Association ends from QInstanceSpecification
    const QSet<QClassifier *> *classifiers() const;
    void addClassifier(QClassifier *classifier);
    void removeClassifier(QClassifier *classifier);
    QValueSpecification *specification() const;
    void setSpecification(QValueSpecification *specification);
    const QSet<QSlot *> *slots_() const;
    void addSlot_(QSlot *slot_);
    void removeSlot_(QSlot *slot_);

protected:
    explicit QInstanceSpecification(QInstanceSpecificationPrivate &dd, QObject *parent = 0);

private:
    QDeployedArtifact *_wrappedDeployedArtifact;
    QPackageableElement *_wrappedPackageableElement;
    QDeploymentTarget *_wrappedDeploymentTarget;
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE_QTUML(QInstanceSpecification) *)
Q_DECLARE_METATYPE(const QSet<QT_PREPEND_NAMESPACE_QTUML(QInstanceSpecification) *> *)
Q_DECLARE_METATYPE(const QList<QT_PREPEND_NAMESPACE_QTUML(QInstanceSpecification) *> *)

QT_END_HEADER

#endif // QTUML_QINSTANCESPECIFICATION_H

