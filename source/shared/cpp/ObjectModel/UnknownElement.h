#pragma once

#include "pch.h"
#include "BaseCardElement.h"
#include "Enums.h"
#include <time.h>
#include "ElementParserRegistration.h"
#include "DateTimePreparser.h"

namespace AdaptiveSharedNamespace
{
    class UnknownElement : public BaseCardElement
    {
    public:
        UnknownElement();
    };

    class UnknownElementParser : public BaseCardElementParser
    {
    public:
        UnknownElementParser() = default;
        UnknownElementParser(const UnknownElementParser&) = default;
        UnknownElementParser(UnknownElementParser&&) = default;
        UnknownElementParser& operator=(const UnknownElementParser&) = default;
        UnknownElementParser& operator=(UnknownElementParser&&) = default;
        virtual ~UnknownElementParser() = default;

        std::shared_ptr<BaseCardElement> Deserialize(ParseContext& context, const Json::Value& root) override;
        std::shared_ptr<BaseCardElement> DeserializeFromString(ParseContext& context, const std::string& jsonString) override;
    };
}
