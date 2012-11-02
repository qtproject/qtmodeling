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

#include "qartifact.h"
#include "qartifact_p.h"

#include <QtUml/QOperation>
#include <QtUml/QProperty>
#include <QtUml/QManifestation>

QT_BEGIN_NAMESPACE_QTUML

QArtifactPrivate::QArtifactPrivate() :
    ownedOperations(new QList<QOperation *>),
    ownedAttributes(new QList<QProperty *>),
    manifestations(new QSet<QManifestation *>),
    nestedArtifacts(new QSet<QArtifact *>)
{
}

QArtifactPrivate::~QArtifactPrivate()
{
    delete ownedOperations;
    delete ownedAttributes;
    delete manifestations;
    delete nestedArtifacts;
}

/*!
    \class QArtifact

    \inmodule QtUml

    \brief An artifact is the source of a deployment to a node.An artifact is the specification of a physical piece of information that is used or produced by a software development process, or by deployment and operation of a system. Examples of artifacts include model files, source files, scripts, and binary executable files, a table in a database system, a development deliverable, or a word-processing document, a mail message.
 */

QArtifact::QArtifact(QObject *parent) :
    QObject(*new QArtifactPrivate, parent),
    _wrappedDeployedArtifact(new QDeployedArtifact(this)),
    _wrappedClassifier(new QClassifier(this))
{
}

QArtifact::QArtifact(QArtifactPrivate &dd, QObject *parent) :
    QObject(dd, parent),
    _wrappedDeployedArtifact(new QDeployedArtifact(this)),
    _wrappedClassifier(new QClassifier(this))
{
}

QArtifact::~QArtifact()
{
}

/*!
    A concrete name that is used to refer to the Artifact in a physical context. Example: file system name, universal resource locator.
 */
QString QArtifact::fileName() const
{
    // This is a read-write attribute

    Q_D(const QArtifact);
    return d->fileName;
}

void QArtifact::setFileName(QString fileName)
{
    // This is a read-write attribute

    Q_D(QArtifact);
    if (d->fileName != fileName) {
        d->fileName = fileName;
    }
}

/*!
    The Operations defined for the Artifact. The association is a specialization of the ownedMember association.
 */
const QList<QOperation *> *QArtifact::ownedOperations() const
{
    // This is a read-write association end

    Q_D(const QArtifact);
    return d->ownedOperations;
}

void QArtifact::addOwnedOperation(QOperation *ownedOperation)
{
    // This is a read-write association end

    Q_D(QArtifact);
    if (!d->ownedOperations->contains(ownedOperation)) {
        d->ownedOperations->append(ownedOperation);

        // Adjust subsetted property(ies)
        d->QClassifierPrivate::addFeature(dynamic_cast<QFeature *>(ownedOperation));
        d->QNamespacePrivate::addOwnedMember(dynamic_cast<QNamedElement *>(ownedOperation));
    }
}

void QArtifact::removeOwnedOperation(QOperation *ownedOperation)
{
    // This is a read-write association end

    Q_D(QArtifact);
    if (d->ownedOperations->contains(ownedOperation)) {
        d->ownedOperations->removeAll(ownedOperation);

        // Adjust subsetted property(ies)
        d->QClassifierPrivate::removeFeature(dynamic_cast<QFeature *>(ownedOperation));
        d->QNamespacePrivate::removeOwnedMember(dynamic_cast<QNamedElement *>(ownedOperation));
    }
}

/*!
    The attributes or association ends defined for the Artifact. The association is a specialization of the ownedMember association.
 */
const QList<QProperty *> *QArtifact::ownedAttributes() const
{
    // This is a read-write association end

    Q_D(const QArtifact);
    return d->ownedAttributes;
}

void QArtifact::addOwnedAttribute(QProperty *ownedAttribute)
{
    // This is a read-write association end

    Q_D(QArtifact);
    if (!d->ownedAttributes->contains(ownedAttribute)) {
        d->ownedAttributes->append(ownedAttribute);

        // Adjust subsetted property(ies)
        d->QNamespacePrivate::addOwnedMember(dynamic_cast<QNamedElement *>(ownedAttribute));
        d->QClassifierPrivate::addAttribute(dynamic_cast<QProperty *>(ownedAttribute));
    }
}

void QArtifact::removeOwnedAttribute(QProperty *ownedAttribute)
{
    // This is a read-write association end

    Q_D(QArtifact);
    if (d->ownedAttributes->contains(ownedAttribute)) {
        d->ownedAttributes->removeAll(ownedAttribute);

        // Adjust subsetted property(ies)
        d->QNamespacePrivate::removeOwnedMember(dynamic_cast<QNamedElement *>(ownedAttribute));
        d->QClassifierPrivate::removeAttribute(dynamic_cast<QProperty *>(ownedAttribute));
    }
}

/*!
    The set of model elements that are manifested in the Artifact. That is, these model elements are utilized in the construction (or generation) of the artifact.
 */
const QSet<QManifestation *> *QArtifact::manifestations() const
{
    // This is a read-write association end

    Q_D(const QArtifact);
    return d->manifestations;
}

void QArtifact::addManifestation(QManifestation *manifestation)
{
    // This is a read-write association end

    Q_D(QArtifact);
    if (!d->manifestations->contains(manifestation)) {
        d->manifestations->insert(manifestation);

        // Adjust subsetted property(ies)
        d->QElementPrivate::addOwnedElement(dynamic_cast<QElement *>(manifestation));
        QNamedElement::addClientDependency(dynamic_cast<QDependency *>(manifestation));
    }
}

void QArtifact::removeManifestation(QManifestation *manifestation)
{
    // This is a read-write association end

    Q_D(QArtifact);
    if (d->manifestations->contains(manifestation)) {
        d->manifestations->remove(manifestation);

        // Adjust subsetted property(ies)
        d->QElementPrivate::removeOwnedElement(dynamic_cast<QElement *>(manifestation));
        QNamedElement::removeClientDependency(dynamic_cast<QDependency *>(manifestation));
    }
}

/*!
    The Artifacts that are defined (nested) within the Artifact. The association is a specialization of the ownedMember association from Namespace to NamedElement.
 */
const QSet<QArtifact *> *QArtifact::nestedArtifacts() const
{
    // This is a read-write association end

    Q_D(const QArtifact);
    return d->nestedArtifacts;
}

void QArtifact::addNestedArtifact(QArtifact *nestedArtifact)
{
    // This is a read-write association end

    Q_D(QArtifact);
    if (!d->nestedArtifacts->contains(nestedArtifact)) {
        d->nestedArtifacts->insert(nestedArtifact);

        // Adjust subsetted property(ies)
        d->QNamespacePrivate::addOwnedMember(dynamic_cast<QNamedElement *>(nestedArtifact));
    }
}

void QArtifact::removeNestedArtifact(QArtifact *nestedArtifact)
{
    // This is a read-write association end

    Q_D(QArtifact);
    if (d->nestedArtifacts->contains(nestedArtifact)) {
        d->nestedArtifacts->remove(nestedArtifact);

        // Adjust subsetted property(ies)
        d->QNamespacePrivate::removeOwnedMember(dynamic_cast<QNamedElement *>(nestedArtifact));
    }
}

// Overriden methods for subsetted properties

void QArtifact::addClientDependency(QManifestation *manifestation)
{
    addManifestation(manifestation);
}

void QArtifact::removeClientDependency(QManifestation *manifestation)
{
    removeManifestation(manifestation);
}

#include "moc_qartifact.cpp"

QT_END_NAMESPACE_QTUML

