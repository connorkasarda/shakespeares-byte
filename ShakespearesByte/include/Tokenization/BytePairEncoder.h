#ifndef BYTE_PAIR_ENCODER_H
#define BYTE_PAIR_ENCODER_H

#include <string>
#include <unordered_map>

namespace ShakespearesByte
{
    /**

    */
    class BytePairEncoder
    {
        public:
            /**
            
            */
            BytePairEncoder() = default;

            /**

            */
            ~BytePairEncoder() = default;

            /**
            @brief Trains the tokenizer using BPE merging strategies
            @param corpusFilename Directory location of the corpus file
            @param numberOfMerges Number of merge operations in BPE
            */
            void learn(const std::string& corpusFilename,
                int numberOfMerges);
        private:
            /**
            @brief Stores the vocabulary as token paired with corpus frequency
            */
            std::unordered_map<std::string, int> token2FrequencyMap {};

            /**
            @brief Produces initial token-frequency pairs and stores them
            @param corpusFilename Directory location of the corpus file
            */
            void initializeVocabulary(const std::string& corpusFilename);
    }; // class BytePairEncoder
} // namespace ShakespearesByte

#endif // BYTE_PAIR_ENCODER_H
