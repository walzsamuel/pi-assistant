module.exports = {
    root: true,
    env: {
        node: true
    },
    'extends': [
        'plugin:vue/essential',
        '@vue/airbnb'
    ],
    rules: {
        'no-console': process.env.NODE_ENV === 'production' ? 'error' : 'off',
        'no-debugger': process.env.NODE_ENV === 'production' ? 'error' : 'off',
        'linebreak-style': 'off',
        'indent': ['warn', 4],
        'max-len': ['warn', { 'code': 160 }],
        'arrow-parens': ['error', 'as-needed'],
        'no-unused-vars': 'warn',
        'no-param-reassign': 'off',
    },
    parserOptions: {
        parser: 'babel-eslint'
    }
};
