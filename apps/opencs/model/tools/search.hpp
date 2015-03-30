#ifndef CSM_TOOLS_SEARCH_H
#define CSM_TOOLS_SEARCH_H

#include <string>
#include <set>

#include <QRegExp>
#include <QMetaType>

class QModelIndex;

namespace CSMDoc
{
    class Messages;
}

namespace CSMWorld
{
    class IdTableBase;
    class UniversalId;
}

namespace CSMTools
{
    class Search
    {
        public:

            enum Type
            {
                Type_Text = 0,
                Type_TextRegEx = 1,
                Type_Id = 2,
                Type_IdRegEx = 3,
                Type_RecordState = 4,
                Type_None
            };

        private:

            Type mType;
            std::string mText;
            QRegExp mRegExp;
            int mValue;
            std::set<int> mColumns;
            int mIdColumn;
            int mTypeColumn;

            void searchTextCell (const CSMWorld::IdTableBase *model, const QModelIndex& index,
                const CSMWorld::UniversalId& id, CSMDoc::Messages& messages) const;

            void searchRegExCell (const CSMWorld::IdTableBase *model, const QModelIndex& index,
                const CSMWorld::UniversalId& id, CSMDoc::Messages& messages) const;

            void searchRecordStateCell (const CSMWorld::IdTableBase *model,
                const QModelIndex& index, const CSMWorld::UniversalId& id,
                CSMDoc::Messages& messages) const;

            QString formatDescription (const QString& description, int pos, int length) const;

            QString flatten (const QString& text) const;
            
        public:

            Search();
        
            Search (Type type, const std::string& value);

            Search (Type type, const QRegExp& value);

            Search (Type type, int value);

            // Configure search for the specified model.
            void configure (const CSMWorld::IdTableBase *model);

            // Search row in \a model and store results in \a messages.
            //
            // \attention *this needs to be configured for \a model.
            void searchRow (const CSMWorld::IdTableBase *model, int row,
                CSMDoc::Messages& messages) const;
    };
}

Q_DECLARE_METATYPE (CSMTools::Search)

#endif
