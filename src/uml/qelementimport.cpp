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
** rights. These rights are described in the Nokia Qt LGPL Exception
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

#include "qelementimport.h"
#include "qelementimport_p.h"

#include <QtUml/QPackageableElement>
#include <QtUml/QNamespace>

QT_BEGIN_NAMESPACE_QTUML

QElementImportPrivate::QElementImportPrivate() :
    visibility(QtUml::VisibilityPublic),
    importedElement(0),
    importingNamespace(0)
{
}

QElementImportPrivate::~QElementImportPrivate()
{
}

/*!
    \class QElementImport

    \inmodule QtUml

    \brief An element import identifies an element in another package, and allows the element to be referenced using its name without a qualifier.
 */

QElementImport::QElementImport(QObject *parent) :
    QDirectedRelationship(*new QElementImportPrivate, parent)
{
    qRegisterMetaType<QElementImport *>("QElementImport *");
    qRegisterMetaType<const QSet<QElementImport *> *>("const QSet<QElementImport *> *");
    qRegisterMetaType<const QList<QElementImport *> *>("const QList<QElementImport *> *");
}

QElementImport::QElementImport(QElementImportPrivate &dd, QObject *parent) :
    QDirectedRelationship(dd, parent)
{
    qRegisterMetaType<QElementImport *>("QElementImport *");
    qRegisterMetaType<const QSet<QElementImport *> *>("const QSet<QElementImport *> *");
    qRegisterMetaType<const QList<QElementImport *> *>("const QList<QElementImport *> *");
}

QElementImport::~QElementImport()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QElementImport
// ---------------------------------------------------------------

/*!
    Specifies the name that should be added to the namespace of the importing package in lieu of the name of the imported packagable element. The aliased name must not clash with any other member name in the importing package. By default, no alias is used.
 */
QString QElementImport::alias() const
{
    // This is a read-write attribute

    Q_D(const QElementImport);
    return d->alias;
}

void QElementImport::setAlias(QString alias)
{
    // This is a read-write attribute

    Q_D(QElementImport);
    if (d->alias != alias) {
        d->alias = alias;
    }
}

/*!
    Specifies the visibility of the imported PackageableElement within the importing Package. The default visibility is the same as that of the imported element. If the imported element does not have a visibility, it is possible to add visibility to the element import.
 */
QtUml::VisibilityKind QElementImport::visibility() const
{
    // This is a read-write attribute

    Q_D(const QElementImport);
    return d->visibility;
}

void QElementImport::setVisibility(QtUml::VisibilityKind visibility)
{
    // This is a read-write attribute

    Q_D(QElementImport);
    if (d->visibility != visibility) {
        d->visibility = visibility;
    }
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QElementImport
// ---------------------------------------------------------------

/*!
    Specifies the PackageableElement whose name is to be added to a Namespace.
 */
QPackageableElement *QElementImport::importedElement() const
{
    // This is a read-write association end

    Q_D(const QElementImport);
    return d->importedElement;
}

void QElementImport::setImportedElement(QPackageableElement *importedElement)
{
    // This is a read-write association end

    Q_D(QElementImport);
    if (d->importedElement != importedElement) {
        // Adjust subsetted property(ies)
        (qtuml_object_cast<QDirectedRelationshipPrivate *>(d))->removeTarget(qtuml_object_cast<QElement *>(d->importedElement));

        d->importedElement = importedElement;

        // Adjust subsetted property(ies)
        if (importedElement) {
            (qtuml_object_cast<QDirectedRelationshipPrivate *>(d))->addTarget(qtuml_object_cast<QElement *>(importedElement));
        }
    }
}

/*!
    Specifies the Namespace that imports a PackageableElement from another Package.
 */
QNamespace *QElementImport::importingNamespace() const
{
    // This is a read-write association end

    Q_D(const QElementImport);
    return d->importingNamespace;
}

void QElementImport::setImportingNamespace(QNamespace *importingNamespace)
{
    // This is a read-write association end

    Q_D(QElementImport);
    if (d->importingNamespace != importingNamespace) {
        // Adjust opposite property
        if (d->importingNamespace)
            d->importingNamespace->removeElementImport(this);

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QDirectedRelationshipPrivate *>(d))->removeSource(qtuml_object_cast<QElement *>(d->importingNamespace));

        d->importingNamespace = importingNamespace;

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QElementPrivate *>(d))->setOwner(qtuml_object_cast<QElement *>(importingNamespace));
        if (importingNamespace) {
            (qtuml_object_cast<QDirectedRelationshipPrivate *>(d))->addSource(qtuml_object_cast<QElement *>(importingNamespace));
        }

        // Adjust opposite property
        if (importingNamespace)
            importingNamespace->addElementImport(this);
    }
}

/*!
    The query getName() returns the name under which the imported PackageableElement will be known in the importing namespace.
 */
QString QElementImport::getName() const
{
    qWarning("QElementImport::getName: operation to be implemented");
}

#include "moc_qelementimport.cpp"

QT_END_NAMESPACE_QTUML

