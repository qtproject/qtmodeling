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
#ifndef QTUML_QCOMBINEDFRAGMENT_H
#define QTUML_QCOMBINEDFRAGMENT_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtUml/QInteractionFragment>

// QtUml includes
#include <QtUml/QtUmlEnumerations>

// Qt includes
#include <QtCore/QList>
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for function parameters
class QGate;
class QInteractionOperand;

class QCombinedFragmentPrivate;

class Q_UML_EXPORT QCombinedFragment : public QInteractionFragment
{
    Q_OBJECT

    Q_PROPERTY(QtUml::InteractionOperatorKind interactionOperator READ interactionOperator WRITE setInteractionOperator)
    Q_PROPERTY(const QSet<QGate *> * cfragmentGates READ cfragmentGates)
    Q_PROPERTY(const QList<QInteractionOperand *> * operands READ operands)

    Q_DISABLE_COPY(QCombinedFragment)
    Q_DECLARE_PRIVATE(QCombinedFragment)

public:
    Q_INVOKABLE explicit QCombinedFragment(QtMof::QMofObject *parent = 0, QtMof::QMofObject *wrapper = 0);
    virtual ~QCombinedFragment();

    // Attributes from QCombinedFragment
    Q_INVOKABLE QtUml::InteractionOperatorKind interactionOperator() const;
    Q_INVOKABLE void setInteractionOperator(QtUml::InteractionOperatorKind interactionOperator);

    // Association ends from QCombinedFragment
    Q_INVOKABLE const QSet<QGate *> *cfragmentGates() const;
    Q_INVOKABLE void addCfragmentGate(QGate *cfragmentGate);
    Q_INVOKABLE void removeCfragmentGate(QGate *cfragmentGate);
    Q_INVOKABLE const QList<QInteractionOperand *> *operands() const;
    Q_INVOKABLE void addOperand(QInteractionOperand *operand);
    Q_INVOKABLE void removeOperand(QInteractionOperand *operand);

protected:
    explicit QCombinedFragment(QCombinedFragmentPrivate &dd, QtMof::QMofObject *parent = 0, QtMof::QMofObject *wrapper = 0);
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE_QTUML(QCombinedFragment) *)
Q_DECLARE_METATYPE(const QSet<QT_PREPEND_NAMESPACE_QTUML(QCombinedFragment) *> *)
Q_DECLARE_METATYPE(const QList<QT_PREPEND_NAMESPACE_QTUML(QCombinedFragment) *> *)

QT_END_HEADER

#endif // QTUML_QCOMBINEDFRAGMENT_H

