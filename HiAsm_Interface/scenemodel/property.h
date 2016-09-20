#pragma once

//Project
#include "value.h"
#include "valuetypes.h"
#include "cgt/CGTShare.h"

//STL

//Qt
#include <QObject>

class SceneModel;
class Element;

class Property : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Property)

private:
    //Self
    QString m_name;
    DataType m_type{};
    bool m_isDefProp{};

    //Value
    Value m_value;

public:
    explicit Property(DataType type = data_null,
                      const QVariant &data = QVariant(),
                      const QString &name = QString());

public:
    //Self
    void setName(const QString &name);
    QString getName() const;
    Element *getParent() const;
    void setIsDefProp(bool value);
    bool getIsDefProp() const;

    void setType(DataType type);
    DataType getType() const;

    //Value
    void setValue(DataType type = data_null,
                  const QVariant &data = QVariant(),
                  const QString &name = QString(),
                  DataType arrayType = data_null);

    Value *getValue() const;
    uchar toByte() const;
    qint32 toInt() const;
    qreal toReal() const;
    QString toString() const;
    SharedLinkedElementInfo toLinkedElementInfo() const;
};