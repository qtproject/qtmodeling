/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtMof module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef QMOFNAMEDELEMENT_H
#define QMOFNAMEDELEMENT_H

#include <QtMof/QtMofGlobal>

// Base class includes
#include <QtMof/QMofElement>

// QtMof includes
#include <QtMof/QtMofNamespace>

// Qt includes
#include <QtCore/QString>
#include <QtCore/QList>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtMof)

// Forward decls for function parameters
class QMofNamespace;
class QMofNamedElement;

class QMofNamedElementPrivate;

class Q_MOF_EXPORT QMofNamedElement : public QMofElement
{
    Q_OBJECT
    Q_CLASSINFO("MetaModelPrefix", "QMof")

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QtMof::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QString qualifiedName READ qualifiedName STORED false)
    Q_PROPERTY(QMofNamespace * namespace_ READ namespace_)

    Q_DISABLE_COPY(QMofNamedElement)
    Q_DECLARE_PRIVATE(QMofNamedElement)

public:
    Q_INVOKABLE explicit QMofNamedElement(QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
    virtual ~QMofNamedElement();

    // Attributes from QMofNamedElement
    Q_INVOKABLE QString name() const;
    Q_INVOKABLE void setName(QString name);
    Q_INVOKABLE QtMof::VisibilityKind visibility() const;
    Q_INVOKABLE void setVisibility(QtMof::VisibilityKind visibility);
    Q_INVOKABLE QString qualifiedName() const;

    // Association ends from QMofNamedElement
    Q_INVOKABLE QMofNamespace *namespace_() const;

    // Operations
    Q_INVOKABLE QList<QMofNamespace *> allNamespaces() const;
    Q_INVOKABLE bool isDistinguishableFrom(const QMofNamedElement *n, const QMofNamespace *ns) const;
    Q_INVOKABLE QString separator() const;

    virtual void setPropertyData();

    // Classes which access read-only opposite properties should be friend
    friend class QMofNamespacePrivate;

protected:
    explicit QMofNamedElement(QMofNamedElementPrivate &dd, QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QMOFNAMEDELEMENT_H

