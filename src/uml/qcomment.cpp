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

#include "qcomment.h"
#include "qcomment_p.h"

#include <QtWrappedObjects/QtWrappedObjectsEnumerations>

QT_BEGIN_NAMESPACE_QTUML

QCommentPrivate::QCommentPrivate()
{
}

QCommentPrivate::~QCommentPrivate()
{
}

/*!
    \class QComment

    \inmodule QtUml

    \brief A comment is a textual annotation that can be attached to a set of elements.
 */

QComment::QComment(QWrappedObject *parent, QWrappedObject *wrapper) :
    QElement(*new QCommentPrivate, parent, wrapper)
{
    setPropertyData();
}

QComment::QComment(QCommentPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QElement(dd, parent, wrapper)
{
    setPropertyData();
}

QComment::~QComment()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QComment
// ---------------------------------------------------------------

/*!
    Specifies a string that is the comment.
 */
QString QComment::body() const
{
    // This is a read-write attribute

    Q_D(const QComment);
    return d->body;
}

void QComment::setBody(QString body)
{
    // This is a read-write attribute

    Q_D(QComment);
    if (d->body != body) {
        d->body = body;
    }
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QComment
// ---------------------------------------------------------------

/*!
    References the Element(s) being commented.
 */
QSet<QElement *> QComment::annotatedElements() const
{
    // This is a read-write association end

    Q_D(const QComment);
    return d->annotatedElements;
}

void QComment::addAnnotatedElement(QElement *annotatedElement)
{
    // This is a read-write association end

    Q_D(QComment);
    if (!d->annotatedElements.contains(annotatedElement)) {
        d->annotatedElements.insert(annotatedElement);
    }
}

void QComment::removeAnnotatedElement(QElement *annotatedElement)
{
    // This is a read-write association end

    Q_D(QComment);
    if (d->annotatedElements.contains(annotatedElement)) {
        d->annotatedElements.remove(annotatedElement);
    }
}

void QComment::registerMetaTypes() const
{
    QElement::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

void QComment::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QComment")][QString::fromLatin1("body")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QComment")][QString::fromLatin1("body")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QComment")][QString::fromLatin1("body")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Specifies a string that is the comment.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QComment")][QString::fromLatin1("body")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QComment")][QString::fromLatin1("body")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QComment")][QString::fromLatin1("annotatedElements")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QComment")][QString::fromLatin1("annotatedElements")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QComment")][QString::fromLatin1("annotatedElements")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("References the Element(s) being commented.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QComment")][QString::fromLatin1("annotatedElements")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QComment")][QString::fromLatin1("annotatedElements")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");

    QElement::setPropertyData();
}

#include "moc_qcomment.cpp"

QT_END_NAMESPACE_QTUML

