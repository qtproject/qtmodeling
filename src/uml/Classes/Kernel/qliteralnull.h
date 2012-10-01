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
#ifndef QTUML_CLASSES_KERNEL_QLITERALNULL_H
#define QTUML_CLASSES_KERNEL_QLITERALNULL_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QLiteralSpecification>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML_CLASSES_KERNEL

QT_MODULE(QtUml)

class QLiteralNullPrivate;

class Q_UML_EXPORT QLiteralNull : public QObject, public QLiteralSpecification
{
    Q_OBJECT

    // From QElement
    Q_PROPERTY(QList<QComment *> * ownedComment READ ownedComment)
    Q_PROPERTY(const QList<QElement *> * ownedElement READ ownedElement)
    Q_PROPERTY(const QElement * owner READ owner)

    // From QNamedElement
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString qualifiedName READ qualifiedName)
    Q_PROPERTY(QEnumerations::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(const QNamespace * namespace_ READ namespace_)

    // From QPackageableElement
    Q_PROPERTY(QEnumerations::VisibilityKind visibility READ visibility WRITE setVisibility)

    // From QTypedElement
    Q_PROPERTY(QType * type READ type WRITE setType)

public:
    explicit QLiteralNull(QObject *parent = 0);
    virtual ~QLiteralNull();

    // Operations (including accessors for derived && !derivedUnion attributes and association-ends)
    bool isComputable() const;
    bool isNull() const;

private:
    Q_DISABLE_COPY(QLiteralNull)
    Q_DECLARE_PRIVATE(QLiteralNull)
};

QT_END_NAMESPACE_QTUML_CLASSES_KERNEL

Q_DECLARE_METATYPE(QList<QtUml::Classes::Kernel::QLiteralNull *>)
Q_DECLARE_METATYPE(QList<QtUml::Classes::Kernel::QLiteralNull *> *)

QT_END_HEADER

#endif // QTUML_CLASSES_KERNEL_QLITERALNULL_H
