#pragma once

#include "pch.h"
#include "Enums.h"
#include "Fact.h"
#include "BaseCardElement.h"
#include "ElementParserRegistration.h"

namespace AdaptiveSharedNamespace
{
    class BaseCardElement;
    class FactSet : public BaseCardElement
    {
        friend class FactSetParser;

    public:
        FactSet();

        Json::Value SerializeToJsonValue() const override;

        std::vector<std::shared_ptr<Fact>>& GetFacts();
        const std::vector<std::shared_ptr<Fact>>& GetFacts() const;

        void SetLanguage(const std::string& value);

    private:
        void PopulateKnownPropertiesSet() override;

        std::vector<std::shared_ptr<Fact>> m_facts;
    };

    class FactSetParser : public BaseCardElementParser
    {
    public:
        FactSetParser() = default;
        FactSetParser(const FactSetParser&) = default;
        FactSetParser(FactSetParser&&) = default;
        FactSetParser& operator=(const FactSetParser&) = default;
        FactSetParser& operator=(FactSetParser&&) = default;
        ~FactSetParser() = default;

        std::shared_ptr<BaseCardElement> Deserialize(ParseContext& context, const Json::Value& root) override;
        std::shared_ptr<BaseCardElement> DeserializeFromString(ParseContext& context, const std::string& jsonString) override;
    };
}
