<template>
    <div id="app">
        <div id="nav">
            <router-link to="/login">Login</router-link> |
            <router-link to="/register">Register</router-link>
        </div>
        <transition name="router-anim">
            <router-view/>
        </transition>
    </div>
</template>

<style>

    body {
        background: rgb(233, 233, 233);
        font-family: Arial, Helvetica, sans-serif;
    }
    html, body {
        height: calc(100% - 50px);
    }

    #app {
        background: #fff;
        width: 50%;
        padding: 30px;
        border-radius: 10px;
        margin: 50px auto 0 auto;
        height: calc(60% - 50px);
    }

    .page {
        position: fixed;
        width: inherit;
    }

    .router-anim-enter-active {
        animation: coming .7s;
        animation-delay: .4s;
        opacity: 0;
    }

    .router-anim-leave-active {
        animation: going .7s;
    }

    @keyframes going {
        from {
            transform: translateX(0);
        }
        to {
            transform: translateX(-30px);
            opacity: 0;
        }
    }

    @keyframes coming {
        from {
            transform: translateX(-30px);
            opacity: 0;
        }
        to {
            transform: translateX(0px);
            opacity: 1;
        }
    }

</style>
