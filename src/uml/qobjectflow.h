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
#ifndef QTUML_QOBJECTFLOW_H
#define QTUML_QOBJECTFLOW_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QActivityEdge>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

class QObjectFlowPrivate;
class QBehavior;

class Q_UML_EXPORT QObjectFlow : public QObject, public QActivityEdge
{
    Q_OBJECT

    // From QElement
    Q_PROPERTY(const QSet<QElement *> * ownedElements READ ownedElements)
    Q_PROPERTY(QElement * owner READ owner)
    Q_PROPERTY(const QSet<QComment *> * ownedComments READ ownedComments)

    // From QNamedElement
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QString qualifiedName READ qualifiedName)
    Q_PROPERTY(QStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(QNamespace * namespace_ READ namespace_)
    Q_PROPERTY(const QSet<QDependency *> * clientDependencies READ clientDependencies)

    // From QRedefinableElement
    Q_PROPERTY(bool isLeaf READ isLeaf WRITE setLeaf)
    Q_PROPERTY(const QSet<QRedefinableElement *> * redefinedElements READ redefinedElements)
    Q_PROPERTY(const QSet<QClassifier *> * redefinitionContexts READ redefinitionContexts)

    // From QActivityEdge
    Q_PROPERTY(QActivityNode * source READ source WRITE setSource)
    Q_PROPERTY(const QSet<QActivityEdge *> * redefinedEdges READ redefinedEdges)
    Q_PROPERTY(const QSet<QActivityGroup *> * inGroup READ inGroup)
    Q_PROPERTY(QValueSpecification * guard READ guard WRITE setGuard)
    Q_PROPERTY(const QSet<QActivityPartition *> * inPartition READ inPartition)
    Q_PROPERTY(QActivity * activity READ activity WRITE setActivity)
    Q_PROPERTY(QInterruptibleActivityRegion * interrupts READ interrupts WRITE setInterrupts)
    Q_PROPERTY(QValueSpecification * weight READ weight WRITE setWeight)
    Q_PROPERTY(QStructuredActivityNode * inStructuredNode READ inStructuredNode WRITE setInStructuredNode)
    Q_PROPERTY(QActivityNode * target READ target WRITE setTarget)

    // From QObjectFlow
    Q_PROPERTY(bool isMultireceive READ isMultireceive WRITE setMultireceive)
    Q_PROPERTY(bool isMulticast READ isMulticast WRITE setMulticast)
    Q_PROPERTY(QBehavior * selection READ selection WRITE setSelection)
    Q_PROPERTY(QBehavior * transformation READ transformation WRITE setTransformation)

    Q_DISABLE_COPY(QObjectFlow)

public:
    explicit QObjectFlow(QObject *parent = 0);
    virtual ~QObjectFlow();

    // Attributes
    bool isMultireceive() const;
    void setMultireceive(bool isMultireceive);
    bool isMulticast() const;
    void setMulticast(bool isMulticast);

    // Association-ends
    QBehavior *selection() const;
    void setSelection(QBehavior *selection);
    QBehavior *transformation() const;
    void setTransformation(QBehavior *transformation);

protected:
    explicit QObjectFlow(bool createPimpl, QObject *parent = 0);
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QList<QT_PREPEND_NAMESPACE_QTUML(QObjectFlow) *>)
Q_DECLARE_METATYPE(QList<QT_PREPEND_NAMESPACE_QTUML(QObjectFlow) *> *)

QT_END_HEADER

#endif // QTUML_QOBJECTFLOW_H

