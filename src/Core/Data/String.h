#ifndef STRING_STRUCT_H
#define STRING_STRUCT_H

#include <string>

namespace core {

    struct String {
        String() = default;
        String(const std::string& t_data) : m_data(t_data) {}
        String(const char* t_data) : m_data(t_data) {}

        // Copy constructor and assignment
        String(const String& t_other) : m_data(t_other.m_data) {}
        String& operator=(const String& t_other) {
            m_data = t_other.m_data;
            return *this;
        }

        // Move constructor and assignment
        String(String&& t_other) noexcept : m_data(std::move(t_other.m_data)) {}
        String& operator=(String&& t_other) noexcept {
            m_data = std::move(t_other.m_data);
            return *this;
        }

        bool operator==(const String& t_other) const {
            return m_data == t_other.m_data;
        }

        char& operator[](size_t t_index) {
            return m_data[t_index];
        }

        const char& operator[](size_t t_index) const {
            return m_data[t_index];
        }

        const std::string& GetString() const { return m_data; }
        const char* GetData() const { return m_data.c_str(); }
        size_t Size() const { return m_data.length(); }
        std::string::const_iterator Begin() const { return m_data.begin(); }
        std::string::const_iterator End() const { return m_data.end(); }
        void Resize(size_t t_new_size) {m_data.resize(t_new_size);}

    private:
        std::string m_data;
    };

} // namespace core

namespace std {

    template<>
    struct hash<core::String> {
        size_t operator()(const core::String& s) const noexcept {
            return hash<std::string>()(s.GetData());
        }
    };

}

#endif