//
// Created by DexrnZacAttack on 9/10/25 using zPc-i2.
//
#pragma once

namespace LPP::IO {
    // "You can have nice things if you port them from Java"
    class FileType {
        constexpr FileType(const int id, const bool savable) : mId(id), mIsSavable(savable) {};
    public:

        constexpr bool isSavable() const { return mIsSavable; }

        constexpr operator int() const {
            return mId;
        }

        static const FileType BASIC;
        static const FileType SAVE_FILE;
        static const FileType SAVE_FILE_OLD;
        static const FileType ARCHIVE;
        static const FileType SOUNDBANK;
    private:
        int mId;
        bool mIsSavable;
    };

    constexpr FileType FileType::BASIC{0, false};
    constexpr FileType FileType::SAVE_FILE{1, true};
    constexpr FileType FileType::SAVE_FILE_OLD{2, true};
    constexpr FileType FileType::ARCHIVE{3, true};
    constexpr FileType FileType::SOUNDBANK{4, false};
}