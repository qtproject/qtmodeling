/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtModelingWidgets module of the Qt Toolkit.
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
#include "qmodelingobjectmodel.h"
#include "qmodelingobjectmodel_p.h"

#include <QtCore/QRegularExpression>

#include <QtGui/QFont>

#include <QtWidgets/QApplication>

#include <QtModeling/QModelingObject>

QT_BEGIN_NAMESPACE

/*!
    \class QModelingObjectModel

    \inmodule QtModelingWidgets

    \brief The QModelingObjectModel class provides a Qt model for handling
    with hierarchical model elements.
*/

QModelingObjectModelPrivate::QModelingObjectModelPrivate()
{
}

/*!
    Creates a new QModelingObjectModel with the given \a parent.
*/
QModelingObjectModel::QModelingObjectModel(QObject *parent) :
    QAbstractItemModel(*new QModelingObjectModelPrivate, parent)
{
}

/*!
    Adjusts \a modelingObjects as the top level model elements which should be handled by this QModelingObjectModel.
*/
void QModelingObjectModel::setModelingObjects(QList<QModelingObject *> modelingObjects)
{
    Q_D(QModelingObjectModel);

    beginResetModel();
    d->modelingObjects = modelingObjects;
    endResetModel();
}

/*!
    Returns the top level model elements handled by this QModelingObjectModel.
*/
QList<QModelingObject *> QModelingObjectModel::modelingObjects() const
{
    Q_D(const QModelingObjectModel);

    return d->modelingObjects;
}

/*!
    Returns the QModelIndex which corresponds to the \a parent's child at position \a row, \a column.
*/
QModelIndex QModelingObjectModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_D(const QModelingObjectModel);

    if (d->modelingObjects.isEmpty() || row < 0 || column < 0 || column >= 2 || (parent.isValid() && parent.column() != 0))
        return QModelIndex();

    if (!parent.isValid())
        return createIndex(row, column, static_cast<void *>(d->modelingObjects.at(row)));

    QModelingObject *modelingObject = static_cast<QModelingObject *>(parent.internalPointer());
    if (!modelingObject)
        return QModelIndex();

    return createIndex(row, column, static_cast<void *>(modelingObject->children().at(row)));
}

/*!
    Returns the QModelIndex of the parent of index identified by \a child.
*/
QModelIndex QModelingObjectModel::parent(const QModelIndex &child) const
{
    Q_D(const QModelingObjectModel);

    QModelingObject *modelingObject = static_cast<QModelingObject *>(child.internalPointer());
    if (d->modelingObjects.isEmpty() || !child.isValid() || !modelingObject)
        return QModelIndex();

    QModelingObject *parentModelingObject = dynamic_cast<QModelingObject *>(modelingObject->parent());
    if (!parentModelingObject)
        return QModelIndex();

    QModelingObject *grandParentModelingObject = dynamic_cast<QModelingObject *>(parentModelingObject->parent());
    if (!grandParentModelingObject)
        return createIndex(0, 0, parentModelingObject);

    return createIndex(grandParentModelingObject->children().indexOf(parentModelingObject), 0, static_cast<void *>(parentModelingObject));
}

/*!
    Returns the number of index rows having \a parent as parent.
*/
int QModelingObjectModel::rowCount(const QModelIndex &parent) const
{
    Q_D(const QModelingObjectModel);

    if (d->modelingObjects.isEmpty() || (parent.isValid() && parent.column() != 0))
        return 0;

    if (parent.row() == -1)
        return d->modelingObjects.count();

    QModelingObject *modelingObject = static_cast<QModelingObject *>(parent.internalPointer());
    if (!modelingObject)
        return 0;

    return modelingObject->children().size();
}

/*!
    Returns the number of index columns having \a parent as parent.
*/
int QModelingObjectModel::columnCount(const QModelIndex &parent) const
{
    Q_D(const QModelingObjectModel);

    return (d->modelingObjects.isEmpty() || (parent.isValid() && parent.column() != 0)) ? 0:2;
}

/*!
    Returns the data \a index contains in role \a role.
*/
QVariant QModelingObjectModel::data(const QModelIndex &index, int role) const
{
    Q_D(const QModelingObjectModel);

    if (d->modelingObjects.isEmpty() || index.column() < 0 || index.column() >= 2)
        return QVariant();
    switch (role) {
        case Qt::DisplayRole:
        case Qt::EditRole: {
            QModelingObject *modelingObject = static_cast<QModelingObject *>(index.internalPointer());
            QString elementRole;
            switch (modelingObject->property("role").value<QtModeling::ModelingObjectRole>()) {
            case QtModeling::ModelElementRole:
                elementRole = QStringLiteral("");
                break;
            case QtModeling::ImportedElementRole:
                elementRole = QStringLiteral(" (imported element)");
                break;
            case QtModeling::ImportedPackageRole:
                elementRole = QStringLiteral(" (imported package)");
                break;
            case QtModeling::AppliedProfileRole:
                elementRole = QStringLiteral(" (applied profile)");
                break;
            }
            return index.column() == 0 ? modelingObject->objectName() + elementRole:QString::fromLatin1(modelingObject->metaObject()->className()).remove(QRegularExpression(QStringLiteral("Object$")));
        }
        case Qt::FontRole: {
            QFont font = QApplication::font();
            QModelingObject *modelingObject = static_cast<QModelingObject *>(index.internalPointer());
            if (index.parent().row() == -1 && modelingObject->property("role").value<QtModeling::ModelingObjectRole>() == QtModeling::ModelElementRole)
                font.setBold(true);
            return font;
        }
        case Qt::UserRole: {
            return qVariantFromValue(static_cast<QModelingObject *>(index.internalPointer()));
        }
    }
    return QVariant();
}

/*!
    Ajusts the \a index's data corresponding to role \a role to \a value.
*/
bool QModelingObjectModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return QAbstractItemModel::setData(index, value, role);
}

/*!
    Returns the header data for section \a section and orientation \a orientation corresponding to role \a role.
*/
QVariant QModelingObjectModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if ((section == 0 || section == 1) && orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return QString::fromLatin1(section == 0 ? "Object":"Class");
    return QVariant();
}

/*!
    Returns the flags of item corresponding to \a index.
*/
Qt::ItemFlags QModelingObjectModel::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index);
}

/*!
    Notify views that \a index has been modified.
*/
void QModelingObjectModel::updateIndex(const QModelIndex &index)
{
    if (!index.isValid()) {
        beginResetModel();
        emit layoutChanged();
        endResetModel();
    }
    else
        emit dataChanged(index, index, QVector<int>() << Qt::DisplayRole);
}

/*!
    Delete the model handled by this QModelingObjectModel.
*/
void QModelingObjectModel::clear()
{
    Q_D(QModelingObjectModel);

    beginResetModel();
    d->modelingObjects.clear();
    endResetModel();
}

QT_END_NAMESPACE

