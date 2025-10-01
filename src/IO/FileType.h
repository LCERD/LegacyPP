//
// Created by DexrnZacAttack on 9/10/25 using zPc-i2.
//
#ifndef LEGACYPLUSPLUS_FILETYPE_H
#define LEGACYPLUSPLUS_FILETYPE_H

namespace LPP::IO {
    class FileType {
    public:
        constexpr FileType(const int id, const bool savable) : mId(id), mIsSavable(savable) {}

        constexpr bool isSavable() const { return mIsSavable; }
        constexpr operator int() const { return mId; }
    private:
        const int mId;
        const bool mIsSavable;
    };

    namespace eFileType
    {
        inline static constexpr FileType BASIC{0, false};
        inline static constexpr FileType SAVE_FILE{1, true};
        inline static constexpr FileType SAVE_FILE_OLD{2, true};
        inline static constexpr FileType ARCHIVE{3, true};
        inline static constexpr FileType SOUNDBANK{4, false};
    }
}

#endif